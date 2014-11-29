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
#include "vutil.h"
#include "modules.h"


#define vlog(msg, ...)

//------------------------------------------Testing Core
void test_valloc() {
    int *a, *b, *c;
    
    a = valloc(int, 1);
    b = valloc(int, 1);
    c = valloc(int, 1);
    a[0] = 1;
    b[0] = 1;
    b[1] = 2;
    
    vunit_mesg("~~test_valloc");
    vunit_test("*bad simple counting", valloc_check(1) == 3);
    vunit_test("*false overflow", !vfree_overflow(a));
    vunit_test("*overflow undetected", vfree_overflow(b));
    vfree(a);
    b[1] = ~0;//undo overflow mark
    vfree(b);
    a = valloc(int, 1);
    b = valloc(int, 1);
    vfree(a);
    a = valloc(int, 1);
    vunit_test("*bad tracking", valloc_check(1) == 3);    
cleanup:
    vfree(a);
    vfree(b);
    vfree(c);
}
static int modtest_a, modtest_b;
void modtest1_init(){
    modtest_a=0;
}
void modtest1_run(){
    modtest_a++;
    module_stop("modtest1");
}
void modtest1_end(){
    vunit_test("*single run failed", modtest_a == 1);
    cleanup:
    return;
}
void modtest2_init(){
    modtest_b=0;
}
void modtest2_run(){
    modtest_b++;
    if(modtest_b==10) module_stop("modtest2");
}
void modtest2_end(){
    vunit_test("*loop run failed", modtest_b == 10);
    cleanup:
    return;
}
void test_modules(){
    vunit_mesg("~~test module");
    num_modules(2);
    module(modtest1);
    module(modtest2);
    init_modules();
    run_modules();
    end_modules();
}


int main(int argc, char *argv[]) {
    test_valloc();
    test_modules();
    test_modcurse();
    
    //activate modules
    num_modules(1024);
    module(modcurse);
    //run modules
    init_modules();
    run_modules();
    end_modules();
    return 0;
}
/*
    const char *err_msg = NULL;
    GLFWwindow *window;

    if (!glfwInit()) {
        err_msg = "Can't initialize GLFW";
        goto badend;
    }
    window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if (!window) {
        err_msg = "Can't create window";
        goto badend;
    }
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window)) {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
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
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    goto goodend;
badend:
    vlog(err_msg);
goodend:
    if (window) glfwDestroyWindow(window);
    glfwTerminate();
    if (err_msg)
        return 1;
    return 0;
}
*/
