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

#include <GLFW/glfw3.h>

#include "modcurse.h"
#include "vutil.h"
#include "constants.h"

#define FATAL(msg) exit(1);

static int width = 800;
static int height = 600;
static int fullscr=0;
static int monitor=-1;

static GLFWwindow *_window=NULL;

void create_window(){
    if (!glfwInit()) {
        FATAL("Can't initialize GLFW");   
    }
    _window = glfwCreateWindow(width, height, VESKRL_TITLE, NULL, NULL);
    if (!_window) {
        FATAL("Can't create window");
    }
    glfwMakeContextCurrent(_window);
}

void test_modcurse();
void modcurse_init(){
    //load_settings();
    create_window();
    //draw_intro();
}
void modcurse_run(){
    if(glfwWindowShouldClose(_window)){
        module_stop("modcurse");
    }
    else{
        float ratio;
        int width, height;
        glfwGetFramebufferSize(_window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
}
void modcurse_end(){
    if (_window){
        glfwDestroyWindow(_window);
    }
    _window = NULL;
    glfwTerminate();
}
