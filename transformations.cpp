#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <SOIL.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"

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

GLfloat mix_value=0.2f;

/*

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
*/




void key_callback(GLFWwindow* window,int key,int scancode,int action,int mode)
{
    if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS)
        glfwSetWindowShouldClose(window,GL_TRUE);

    if(key==GLFW_KEY_UP && action==GLFW_PRESS)
    {
        mix_value+=0.1f;
        if(mix_value>1.0f) mix_value=1.0f;
    }

    if(key==GLFW_KEY_DOWN && action==GLFW_PRESS)
    {
        mix_value-=0.1f;
        if(mix_value<0.0f) mix_value=0.0f;
    }
}

int main()
{
    glfwInit();
#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
#endif
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);

    GLFWwindow *window=glfwCreateWindow(800,600,"Learn OpenGL",nullptr,nullptr);
    if(window==nullptr)
    {
        std::cout<<"Failed to create GLFW window!"<<std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glewExperimental=GL_TRUE;
    if(glewInit()!=GLEW_OK)
    {
        std::cout<<"Failed to initialize GLEW!"<<std::endl;
        return -1;
    }

    int width,height;
    glfwGetFramebufferSize(window,&width,&height);
    glViewport(0,0,width,height);

    glfwSetKeyCallback(window,key_callback);

    Shader our_shader("shader.vs","shader.frag");

    GLuint texture1,texture2;

    // generate texture 1
    glGenTextures(1,&texture1);
    glBindTexture(GL_TEXTURE_2D,texture1);
    // set texture parameters
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    // set texture filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    // load, create and generate mipmaps
    unsigned char* image=SOIL_load_image("container.jpg",&width,&height,0,SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    glGenerateMipmap(GL_TEXTURE_2D);
    // free image data
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D,0);

    // generate texture 2
    glGenTextures(1,&texture2);
    glBindTexture(GL_TEXTURE_2D,texture2);
    // set texture parameters
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    // set texture filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    // load, create and generate mipmaps
    image=SOIL_load_image("awesomeface.png",&width,&height,0,SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    glGenerateMipmap(GL_TEXTURE_2D);
    // free image data
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D,0);

    GLfloat vertices[]={
        // positions        // colors           // textures
         0.5f, 0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
         0.5f,-0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
        -0.5f,-0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
        -0.5f, 0.5f, 0.0f,  1.0f, 1.0f, 0.0f,   0.0f, 1.0f
    };

    GLuint indices[]={
        0, 1, 3,
        1, 2, 3
    };

    GLuint VAO,VBO,EBO;
    glGenBuffers(1,&VBO);
    glGenBuffers(1,&EBO);
    glGenVertexArrays(1,&VAO);

    // bind vertex array object
    glBindVertexArray(VAO);

    // copy the vertices in a buffer
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    // copy the index array in an element buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);

    // set position attribute pointers
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8*sizeof(GL_FLOAT),(GLvoid*)0);
    glEnableVertexAttribArray(0);
    // set color attribute pointers
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8*sizeof(GL_FLOAT),(GLvoid*)(3*sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    // set texture attribute pointers
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,8*sizeof(GL_FLOAT),(GLvoid*)(6*sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    // unbind the vertex array object
    glBindVertexArray(0);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(.2f,.3f,.3f,1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        // use shader program
        our_shader.Use();

        // bind textures
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,texture1);
        glUniform1i(glGetUniformLocation(our_shader.program,"our_texture1"),0);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D,texture2);
        glUniform1i(glGetUniformLocation(our_shader.program,"our_texture2"),1);

        glUniform1f(glGetUniformLocation(our_shader.program,"mix_value"),mix_value);

        // generate transformation matrix
        glm::mat4 trans(1.0f);
        trans=glm::translate(trans,glm::vec3(0.5f,-0.5f,0.0f));
        trans=glm::rotate(trans,glm::radians((GLfloat)glfwGetTime()*50.0f),glm::vec3(0.0f,0.0f,1.0f));

        GLuint transform_location=glGetUniformLocation(our_shader.program,"transform");
        glUniformMatrix4fv(transform_location,1,GL_FALSE,glm::value_ptr(trans));

        // draw
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    // deallocate all resources
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    glDeleteBuffers(1,&EBO);
    // terminate GLFW
    glfwTerminate();
/*
    glutDisplayFunc(mydisplay); //displays popup window
    glutIdleFunc(spinDisplay); //makes arms and square spin
    
    glutMainLoop();

*/
    return 0;
}


