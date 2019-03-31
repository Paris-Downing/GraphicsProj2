#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include <iostream>
#include <math.h>
#define DEG_TO_RAD 0.017453
#include <GLFW/glfw3.h>

GLfloat theta = 0.0;

/*
void key_callback(GLFWwindow* window,int key,int scancode,int action,int mode)
{
    if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS)
        glfwSetWindowShouldClose(window,GL_TRUE);
}
*/

void mydisplay(void)
{
    //the shapes will create a new copy for every degree they turn
    glClear(GL_COLOR_BUFFER_BIT);
    //creates square- no square without this line.
    glBegin(GL_POLYGON);

    glColor3f(1.0, 0.0, 0.0);

    //red corner vertex
    glVertex2f(cos(DEG_TO_RAD * theta), sin(DEG_TO_RAD * theta));
    
    //green shading
    glColor3f(0.0, 1.0, 0.0);

    //green corner vertex
    glVertex2f(-sin(DEG_TO_RAD * theta), cos(DEG_TO_RAD * theta));
    //blue shading
    glColor3f(0.0, 0.0, 1.0);
    //blue corner vertex
    glVertex2f(-cos(DEG_TO_RAD * theta), -sin(DEG_TO_RAD * theta));
    //white corner shading
    glColor3f(1.0, 1.0, 1.0);
    //white corner vertex
    glVertex2f(sin(DEG_TO_RAD * theta), -cos(DEG_TO_RAD * theta));
    
    
    //turns stick figure into triangle
    glEnd();

    float x = sin(DEG_TO_RAD * theta);
    float y =  -cos(DEG_TO_RAD * theta);
    
    std::cout << "x" << x << "\n";
    std::cout << "y" << y << "\n";

    //head
    glLineWidth(2.5);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-0.25, 0.5, 0.0);
    glVertex3f(0.25, 0.5, 0.0);
    glEnd();

    glLineWidth(2.5);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.25, 0.5, 0.0);
    glVertex3f(0.25, 1.0, 0.0);
    glEnd();

    glLineWidth(2.5);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.25, 1.0, 0.0);
    glVertex3f(-0.25, 1.0, 0.0);
    glEnd();

    glLineWidth(2.5);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-0.25, 1.0, 0.0);
    glVertex3f(-0.25, 0.5, 0.0);
    glEnd();


    //body
    glLineWidth(2.5);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.5, 0.0);
    glVertex3f(0.0, -0.5, 0.0);
    glEnd();

    //left arm
    glLineWidth(2.5);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.25, 0.0);
    glVertex3f(-0.25, 0.0, 0.0);
    //glVertex3f(x, y + 0.5, -1);
    glEnd();

    //right arm
    glLineWidth(2.5);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.25, 0.0);
    glVertex3f(0.25, 0.0, 0.0);
    //glVertex3f(x, y - 0.5, -1);
    glEnd();

    //left hand
    glLineWidth(2.5);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-0.25, 0.0, 0.0);
    glVertex3f(x+0.0,-y-0.25,0.0);
    glEnd();

    //right hand
    glLineWidth(2.5);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.25, 0.0, 0.0);
    glVertex3f(x+0.0,y-0.25,0.0);
    //starts on (0, -.25)
    //goes to (.25,0)
    //goes to (0,.25)
    //ends at (-.25,0)
    glEnd();

    //left leg
    glLineWidth(2.5);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, -0.5, 0.0);
    glVertex3f(-0.25, -0.75, 0.0);
    glEnd();

    //right leg
    glLineWidth(2.5);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, -0.5, 0.0);
    glVertex3f(0.25,-0.75,0.0);
    glEnd();

    //left foot
    glLineWidth(2.5);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-0.25, -0.75, 0.0);
    glVertex3f(-0.25,-1.0,0.0);
    glEnd();

    //right foot
    glLineWidth(2.5);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.25,-0.75,0.0);
    glVertex3f(0.25,-1.0,0.0);
    glEnd();

    glutSwapBuffers();
}

void spinDisplay(void)
{
    //controls how fast the box is turning
    theta -= 1;

    if (theta < -360.0)
        theta += 360.0;

    //makes the rotation be displayed
    glutPostRedisplay();
}

// void myinit(void)
// {
//     glClearColor(0.0, 0.0, 0.0, 0.0);
//     glColor3f(1.0, 1.0, 1.0);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluOrtho2D(-4.0, 4.0, -4.0, 4.0);
// }

int main(int argc, char **argv)
{
    //creates a window of certain size with the name hello world
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    //GLFWwindow *window=glfwCreateWindow(800,600,"Learn OpenGL",nullptr,nullptr);
    glutCreateWindow("Hello world!");
    /*
    if(window==nullptr)
    {
        std::cout<<"Failed to create GLFW window!"<<std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    */

    glutDisplayFunc(mydisplay); //displays popup window
    glutIdleFunc(spinDisplay); //rotate the square/arms and call this every loop
    
    glutMainLoop();
    return 0;
}
