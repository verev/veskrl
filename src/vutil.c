/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014 verev
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdlib.h>
#include "vutil.h"



int vstrcmp(const char *str1, const char *str2)
{
    int i=0;
    while(str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])i++;
    
    if(str1[i] == '\0' && str2[i] == '\0')return 0;
    else if(str1[i] == '\0' || str1[i] < str2[i])return -i;
    else if(str2[i] == '\0' || str1[i] > str2[i])return i;
    else return 0;
}

int vnstrcmp(const char *str1, const char *str2, int n)
{
    int i=0;
    while(str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i] && i<n)i++;
    
    if(str1[i] == '\0' && str2[i] == '\0')return 0;
    else if(str1[i] == '\0' || str1[i] < str2[i])return -i;
    else if(str2[i] == '\0' || str1[i] > str2[i])return i;
    else return 0;
}


typedef struct TAG_vmem_header {
    int magic;
    const char *file;
    const char *type;
    int line;
    size_t size;
    struct TAG_vmem_header *backlink;
    struct TAG_vmem_header *link;
} vmem_header;

typedef struct TAG_vmem_footer {
    int overflow_check;
} vmem_footer;

static vmem_header *vmem_link_root = NULL;

void *valloc_impl(const char *file, int line, const char *type, size_t size) {
    BYTE *mem = malloc(sizeof (vmem_header) + sizeof (vmem_footer) + size);
    vmem_header *head = (vmem_header*) mem;
    vmem_footer *foot = (vmem_footer*) (mem + sizeof (vmem_header) + size);

    head->magic = VMEM_MAGIC_TOKEN;
    head->file = file;
    head->line = line;
    head->type = type;
    head->size = size;
    head->link = vmem_link_root;
    head->backlink = NULL;

    foot->overflow_check = ~0;

    vmem_link_root = head;
    if (head->link) {
        head->link->backlink = head;
    }

    return (void*) (mem + sizeof (vmem_header));
}

void vfree_impl(const char *file, int line, void *p) {
    if(p == NULL)return;//null pointer, nothing to do here
    vmem_header *head = (vmem_header*) ((BYTE*) p - sizeof (vmem_header));
    vmem_footer *foot = (vmem_footer*) ((BYTE*) p + head->size);
    if(head->magic != VMEM_MAGIC_TOKEN)return;//It's not a vmem pointer
    if (foot->overflow_check != ~0) {
        VUTIL_ALERT("memory overflow: %s allocation at (%s:%d), free at (%s,%d)\n",
                head->type, head->file, head->line, file, line);
    }
    if (head->backlink) {
        head->backlink->link = head->link;
    }
    if (head->link) {
        head->link->backlink = head->backlink;
    }
    if (vmem_link_root == head)vmem_link_root = head->link;
    free((void*) head);
}

int vfree_overflow(void *p) {
    vmem_header *head = (vmem_header*) ((BYTE*) p - sizeof (vmem_header));
    vmem_footer *foot = (vmem_footer*) ((BYTE*) p + head->size);
    if (foot->overflow_check != ~0) {
        return 1;
    }
    return 0;
}

int valloc_check(int silent) {
    vmem_header *node = vmem_link_root;
    int leaks = 0;
    while (node != NULL) {
        if (!silent) {
            VUTIL_ALERT("memory leak: %s allocation at (%s:%d)\n", node->type, node->file, node->line);
        }
        node = node->link;
        leaks++;
    }
    return leaks;
}


#define VMODULES_FLAGS_ACTIVE 1

static struct module_desc{
    int flags;
    const char *name;
    
    void (*init)();
    void (*run)();
    void (*end)();
} **_modlist = NULL;

static unsigned int _modlist_i=0;
static unsigned int _modlist_n=0;


//action =
//0: set false
//1: set true
//else: read it
static int _module_flag_active(struct module_desc* mod, int action){
    if(mod == NULL)return 0;
    switch(action){
        case 1:
            mod->flags = mod->flags | VMODULES_FLAGS_ACTIVE;
            return 1;
        case 0:
            mod->flags = mod->flags & (~VMODULES_FLAGS_ACTIVE);
            return 0;
        default:
            return (mod->flags & VMODULES_FLAGS_ACTIVE) != 0;
    }
}

void num_modules(unsigned int num_mods){
    end_modules();
    vfree(_modlist);
    _modlist = valloc(struct module_desc*, num_mods);
    for(int i=0;i<num_mods;i++)_modlist[i] = NULL;
    _modlist_i=0;
    _modlist_n = num_mods;
}

//adds a modules
void _module_impl(const char *name, void (*init)(), void (*run)(), void (*end)()){
    if(_modlist_i >= _modlist_n){
        VUTIL_ALERT("exceeded module count when adding %s\n", name);
        return;
    }
    struct module_desc *mod = valloc(struct module_desc, 1);
    mod->flags = VMODULES_FLAGS_ACTIVE;
    mod->name = name;
    mod->init = init;
    mod->run = run;
    mod->end = end;
    _modlist[_modlist_i++] = mod;
}

void init_modules(){
    for(int i=0;i<_modlist_i;i++){
        if(_modlist[i] != NULL && _modlist[i]->init != NULL)
            _modlist[i]->init();
    }
}

void run_modules(){
    int stop = 0;
    while(!stop){
        stop = 1;
        for(int i=0;i<_modlist_i;i++){
            if(_modlist[i] != NULL
                    && _modlist[i]->run != NULL 
                    && _module_flag_active(_modlist[i], -1)){
                stop = 0;
                _modlist[i]->run();
            }
        }
    }
}

void end_modules(){
    for(int i=_modlist_i-1;i>=0;i--){
        if(_modlist[i] != NULL && _modlist[i]->init != NULL){
            _modlist[i]->end();
        }
        vfree(_modlist[i]);
    }
}

void module_start(const char *name){
    for(int i=0;i<_modlist_i;i++){
        if(_modlist[i] != NULL && vstrcmp(_modlist[i]->name, name)==0){
            _module_flag_active(_modlist[i], 1);
            break;
        }
    }
}
void module_stop(const char *name){
    for(int i=0;i<_modlist_i;i++){
        if(_modlist[i] != NULL && vstrcmp(_modlist[i]->name, name)==0){
            _module_flag_active(_modlist[i], 0);
            break;
        }
    }
}
