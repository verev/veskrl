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

#ifndef __VUTIL_H__
#define __VUTIL_H__


#define VMEM_MAGIC_TOKEN 0xea7ad1c0

//what do when we must print
#define VUTIL_ALERT(MSG, ...) printf(MSG, ##__VA_ARGS__)
extern int printf(const char * format, ...);

//memory leak detection by ve
//call valloc_check(0); before exiting the program to get list of
//valloc calls without matching vfree
//TODO detect dangling pointers, access to vfree'd memory
//TODO Thread safety
#define valloc(type, num) valloc_impl(__FILE__,__LINE__,#type,sizeof(type)*num)
#define vfree(p) do{vfree_impl(__FILE__,__LINE__,p);p=NULL;}while(0)

//Unit testing system by ve
//functions that define a cleanup: label and call vunit_test
//are unit functions ; when called they run the test, and report failures
#define vunit_test(MSG, TEST) do{if(!(TEST))\
{VUTIL_ALERT(MSG "\n");goto cleanup;}}while(0)
#define vunit_mesg(MSG) VUTIL_ALERT(MSG "\n")


int vstrcmp(const char *str1, const char *str2);
int vnstrcmp(const char *str1, const char *str2, int n);

typedef unsigned char BYTE;

void *valloc_impl(const char *file, int line, const char *type, size_t size);
void vfree_impl(const char *file, int line, void *p);
//check for memory leaks, if silent is 0, we print more info
//returns number of leaks detected
int valloc_check(int silent);
//useful for unit testing, returns 1 if we wrote to beyond the pointer`s size
int vfree_overflow(void *p);


//add a module to the manager ; don't do that after calling init_modules
//make sure they're all loaded before that!!
#define module(name) _module_impl(#name, name ## _init, name ## _run, name ## _end)

void num_modules(unsigned int num_mods);
void _module_impl(const char *name, void (*init)(), void (*run)(), void (*end)());
void init_modules();//calls each module's init, from first to last
void run_modules(); // runs all active modules until none are active
void end_modules(); //calls each module's end, from last to first
void module_start(const char *name);//starts a module again
void module_stop(const char *name);//stops a module; use when its job is done

/*
 * num_modules(512);
 * MODULE(modworkpool);   //manage thread workers
 * MODULE(modcurse);        //manage glfw to create a basic curses API
 * MODULE(modveskrl_game);       //this is the game ; it stops in init
 * MODULE(modveskrl_creator);    //create a new game ; it stops in init
 * MODULE(modveskrl_menu);       //this is the main menu
 */

#endif//__VUTIL_H__
