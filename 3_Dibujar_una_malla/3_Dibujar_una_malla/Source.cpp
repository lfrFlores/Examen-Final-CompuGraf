#include <GL/freeglut.h>

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);


	glColor3f(0.0, 0.0, 0.0);


	int x1 = 0;
	int y1 = 200;
	int x2 = 240;
	int y2 = 360;

	int n = 8;
	for (int i = 0; i<n; i++)
	{
		// una sola linea
		glBegin(GL_LINES);
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
		glEnd();
		x1 = x1 + 10;
		y1 = y1 - 10;
		x2 = x2 + 10;
		y2 = y2 - 10;
	}



	x1 = 0;
	y1 = 230;
	x2 = 230;
	y2 = 0;

	for (int i = 0; i<n; i++)
	{
		// una sola linea
		glBegin(GL_LINES);
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
		glEnd();
		x1 = x1 + 10;
		y1 = y1 + 10;
		x2 = x2 + 10;
		y2 = y2 + 10;
	}


	glFlush();
}

void myResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(400, 100);
	glutCreateWindow("Mi Ventana");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myResize);
	myInit();
	glutMainLoop();
	return 0;
}
