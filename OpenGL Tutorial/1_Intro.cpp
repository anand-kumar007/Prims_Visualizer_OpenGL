#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void display();
void init()
{
    glClearColor(1.0,1.0,0.0,1.0);
}


int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200,100);
    glutInitWindowSize(500,400);
    glutCreateWindow("Window 1 ");


    glutDisplayFunc(display); 
    //after creating the window(registe the callback func)

    init(); //color resetting

    glutMainLoop();
    //requires the callback func just
    //like any other API


    return 0;
}

// g++ main.cpp -lGL -lGLU -lglut

//will be first called while drawing the window
void display()
{
    //frameBuffer flag is to be passed
    //frameBuffer is cleared
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //will reset any matric transformation etc

    //draw stuff onto it



    glFlush(); //will draw stuff on screen


}

/*
actually whatever we are drawing is called are drawn
    called framebuffer (a unit inside a framebuffer correspond
    to a pixel inside the framebuffer)

therfore first clear them first and then go for the
next task after that

1. clear
2. reset
3. draw
4. display


*/