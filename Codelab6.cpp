#include<windows.h>
#include<GL/glut.h>
char title[] = "3D Shape";
void initGL() 
{
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(1.5f,0.0f,-7.0f);
	glBegin(GL_QUADS);
	//green
		glColor3f(0.0f,1.0f,-1.0f);
		glVertex3f(1.0f,1.0f,-1.0f);
		glVertex3f(-1.0f,1.0f,-1.0f);
		glVertex3f(-1.0f,1.0f,1.0f);
		glVertex3f(1.0f,1.0f,1.0f);
	//Orange	
		glColor3f(1.0f,0.5f,0.0f);
		glVertex3f(1.0f,-1.0f,1.0f);
		glVertex3f(-1.0f,-1.0f,1.0f);
		glVertex3f(-1.0f,-1.0f,-1.0f);
		glVertex3f(1.0f,-1.0f,-1.0f);
	//Red
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f(1.0f,1.0f,1.0f);
		glVertex3f(-1.0f,1.0f,1.0f);
		glVertex3f(-1.0f,-1.0f,1.0f);
		glVertex3f(1.0f,-1.0f,1.0f);
	//Yellow
		glColor3f(1.0f,1.0f,1.0f);
		glVertex3f(1.0f,-1.0f,-1.0f);
		glVertex3f(-1.0f,-1.0f,-1.0f);
		glVertex3f(-1.0f,1.0f,-1.0f);
		glVertex3f(1.0f,1.0f,-1.0f);
	//Blue
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3f(-1.0f,1.0f,1.0f);
		glVertex3f(-1.0f,1.0f,-1.0f);
		glVertex3f(-1.0f,-1.0f,-1.0f);
		glVertex3f(-1.0f,-1.0f,1.0f);
	//Magenta
		glColor3f(1.0f,0.0f,1.0f);
		glVertex3f(1.0f,1.0f,-1.0f);
		glVertex3f(1.0f,1.0f,1.0f);
		glVertex3f(1.0f,-1.0f,1.0f);
		glVertex3f(1.0f,-1.0f,-1.0f);
	glEnd();
	
	glLoadIdentity();
	glTranslatef(-1.5f,0.0f,-6.0f);
	glBegin(GL_TRIANGLES);
		//front
		glColor3f(1.0f,0.0f,0.0f); //red
		glVertex3f(0.0f,1.0f,0.0f);
		glColor3f(0.0f,1.0f,0.0f); //green
		glVertex3f(-1.0f,-1.0f,1.0f);
		glColor3f(0.0f,0.0f,1.0f); //blue
		glVertex3f(1.0f,-1.0f,1.0f);
		//right
		glColor3f(1.0f,0.0f,0.0f); //red
		glVertex3f(0.0f,1.0f,0.0f);
		glColor3f(0.0f,1.0f,1.0f); //blue
		glVertex3f(-1.0f,-1.0f,1.0f);
		glColor3f(0.0f,1.0f,0.0f); //green
		glVertex3f(1.0f,-1.0f,-1.0f);
		//back
		glColor3f(1.0f,0.0f,0.0f); //red
		glVertex3f(0.0f,1.0f,0.0f);
		glColor3f(0.0f,1.0f,0.0f); //green
		glVertex3f(-1.0f,-1.0f,-1.0f);
		glColor3f(0.0f,0.0f,1.0f); //blue
		glVertex3f(-1.0f,-1.0f,-1.0f);
		//left
		glColor3f(1.0f,0.0f,0.0f);       // Red
      	glVertex3f( 0.0f, 1.0f, 0.0f);
      	glColor3f(0.0f,0.0f,1.0f);       // Blue
      	glVertex3f(-1.0f,-1.0f,-1.0f);
      	glColor3f(0.0f,1.0f,0.0f);       // Green
      	glVertex3f(-1.0f,-1.0f, 1.0f);
    glEnd();
	glutSwapBuffers();
}
void reshape(GLsizei width, GLsizei height)
{
	if(height == 0) height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0,0, width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,aspect,0.1f,100.0f);	
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(50,50);
	glutCreateWindow(title);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	initGL();
	glutMainLoop();
	return 0;
}

