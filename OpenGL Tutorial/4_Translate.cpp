#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>

void display();
void reshape(int ,int );
void timer(int );

void init()
{
    glClearColor(1,1,0,1);
    glColor3f(1,1,0);
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(200,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Window 1");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutTimerFunc(1000,timer,0);
    init();

    glutMainLoop();

    return 0;

}

float x_position = -10.0;
int state = 1;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity(); 
    //so if we remove it the translation will happen from that point to next 5,5,0 go and try it out

    // translation here
    glTranslatef(5,5,0);

    //draw here
    glBegin(GL_POLYGON);

    glColor3f(1,0,0);
    glVertex2f(-1,1);
    glColor3f(1,0,1);
    glVertex2f(-1,-1);
    glColor3f(1,1,1);
    glVertex2f(1,-1);
    glColor3f(0,0,1);
    glVertex2f(1,1);

    glEnd();
    // glFlush();

    glutSwapBuffers();
}

void reshape(int w,int h)
{

    glViewport(0,0,(GLsizei)w, (GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-10,10,-10,10);

    //change to modelview to display it
    glMatrixMode(GL_MODELVIEW);    



}

void timer(int x)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);


    switch (state)
    {
    case 1:
        if(x_position < 8)
            x_position += 0.5;
        else 
            state = -1;
        break;
    case -1 :
        if(x_position > -10)
            x_position -= 0.15;
        else 
            state = 1;
    }
}
/*

Transformation are of 3 types

1. Translation
2. Rotation
3. Scaling


translate funcn cannot be called within glBegin() and glEnd()

*/  