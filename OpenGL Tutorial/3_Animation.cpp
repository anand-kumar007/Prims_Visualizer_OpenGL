#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void display();
void reshape(int, int);
void timer(int );

void init()
{
    glClearColor(1.0,1.0,0.0,1.0);
    glColor3f(1,0,0); // if for all
}


int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB |GLUT_DOUBLE);
    //double is must bcz two frame buffer during animation

    glutInitWindowPosition(200,100);
    glutInitWindowSize(500,400);
    glutCreateWindow("Window 1 ");


    glutDisplayFunc(display); 
    glutReshapeFunc(reshape);


    //Animation start
    glutTimerFunc(1000,timer, 0);

    //Animation ends

    init(); 

    glutMainLoop();
    

    return 0;
}

// g++ main.cpp -lGL -lGLU -lglut



float x_position = -10.0;
int state = 1; //left or right direction


void display()
{
  
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    //shade model
    glShadeModel(GL_SMOOTH);

    glBegin(GL_POLYGON);

    glColor3f(1,0,0); //for individual primitives
    //color is assigned to edges
    //always the order is counterClockwise
    glVertex2f(x_position,1);
    glVertex2f(x_position,-1);

    // glShadeModel(GL_FLAT);
    glColor3f(0,1,0);
    glVertex2f(x_position+2,-1);
    glColor3f(0,1,1);
    glVertex2f(x_position+2,1);
    



    glEnd();

    // glFlush(); //no more in use (cz double buffer)
    glutSwapBuffers();


}


void reshape(int w, int h)
{

    glViewport(0,0,(GLsizei)w,(GLsizei)h); 
  
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 

    gluOrtho2D(-10,10,-10,10);

    glMatrixMode(GL_MODELVIEW);    

}

void timer(int x){

    glutPostRedisplay();
    //calling the display func to make animation

   
    glutTimerFunc(1000/60,timer,0);

    switch (state)
    {
    case 1:
        if(x_position < 8)
            x_position += 0.75;
        else 
            state = -1;
        break;
    case -1 :
        if(x_position > -10)
            x_position -= 0.15;
        else 
            state = 1;

        break;
    }
  

}


/*

Animation 

again and again at some interval displaying the
item is nothing but animation

need to swich it to Double buffer

we'll have two framebuffer
front buffer (intially on the screen)
back buffer (used to draw objects (will be inside the memory))

once drawing is over we can switch them to give
a feel of animation

again one becomes back and forth swapping etc.



*/