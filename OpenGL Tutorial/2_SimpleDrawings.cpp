#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void display();
void reshape(int, int);

void init()
{
    // glClearColor(1.0,1.0,0.0,1.0);
}


int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200,100);
    glutInitWindowSize(500,400);
    glutCreateWindow("Window 1 ");


    glutDisplayFunc(display); 
    glutReshapeFunc(reshape);
    init(); 

    glutMainLoop();
    

    return 0;
}

// g++ main.cpp -lGL -lGLU -lglut


void display()
{
  
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glPointSize(10.0);

    //draw stuff here
    // glBegin(GL_POINTS);
    glBegin(GL_TRIANGLES);


    glVertex2f(0,5);
    glVertex2f(4,-3);
    glVertex2f(-4,-3);
    

    glVertex2f(0.4,-5);
    glVertex2f(-4,3);
    glVertex2f(-4.3,-3.6);

    // glVertex2f(-0.3,-3); //ignored

    
    //for trianlge 3n points should be given
    //otherwise first 3m are taken and rest are ignored
    //and so on for other polygon

    
    glEnd();

    glFlush();


}

//this is called whenever the window
//is reshaped after being drawn
void reshape(int w, int h)
{

    //we need to change the clipping area
    //when window size changes

    //entire screen we are specifying here
    glViewport(0,0,(GLsizei)w,(GLsizei)h); 
  
    //Projection 
    
    //(default was MODEL_VIEW) and now
    //we are changing it
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); //resests the current matrix

    //left,right,bottom,top
    gluOrtho2D(-10,10,-10,10);

    //lets swithc back to MODELVIEW matrix
    glMatrixMode(GL_MODELVIEW);    


    //go and draw the stuffs

}


/*
How our drawing is clipped onto the screen
for that we should define two things

1. viewport
2. projection


1. Viewport

and we need to space from where viewport is 
specified and that can be done using the resize
function


2. Projection

*/