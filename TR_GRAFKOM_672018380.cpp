#include <iostream>
#include <GL/freeglut.h>

// TOPIC
// Kapal Pesiar - Oasis Of The Seas

// CONTRIBUTOR
// - Rietts Andreas Ruff       672018380
// - Yehezkiel Yeremy Rampen   672018429 

float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown = false;

void handleMouseButton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mousedown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else {
		mousedown = false;
	}

	glutPostRedisplay();
}

void handleMouseMove(int x, int y) {
	if (mousedown) {
		yrot = x - xdiff;
		xrot = y + ydiff;

		glutPostRedisplay();
	}
}

void handleKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
	case 'A':
		// bergeser ke kiri
		glTranslatef(-1.0, 0.0, 0.0);
		break;
	case 'd':
	case 'D':
		// bergeser ke kanan
		glTranslatef(1.0, 0.0, 0.0);
		break;
	case 'w':
	case 'W':
		// bergeser ke atas
		glTranslatef(0.0, 1.0, 0.0);
		break;
	case 's':
	case 'S':
		// bergeser ke bawah
		glTranslatef(0.0, -1.0, 0.0);
		break;
	case 'x':
	case 'X':
		// berotasi ke kanan
		glRotatef(1.0, 0.0, 0.0, -5.0);
		break;
	case 'z':
	case 'Z':
		// berotasi ke kiri
		glRotatef(1.0, 0.0, 0.0, 5.0);
		break;
	case 'c':
	case 'C':
		// perbesar
		glTranslatef(0.0, 0.0, 5.0);
		break;
	case 'v':
	case 'V':
		// perkecil
		glTranslatef(0.0, 0.0, -5.0);
		break;
	}

	glutPostRedisplay();
}

void reshape(int w, int h) {
	if (h == 0) h = 1;

	GLfloat aspect = (GLfloat)w / (GLfloat)h;
	glViewport(0, 25, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, aspect, 0.1f, -1.0f);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	gluLookAt(0, 0, 150, 0, 0, 0, 0, 1, 0);
	glRotatef(xrot, 1, 0, 0);
	glRotatef(yrot, 0, 1, 0);

	// CODE HERE

	glPopMatrix();
	glutSwapBuffers();
}

void initGL() {
	glClearColor(0, 0, 0, 0);
	glLineWidth(2);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 600);
	glutCreateWindow("TR GRAFIKA KOMPUTER ASDOS");
	initGL();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(handleKeyboard);
	glutMouseFunc(handleMouseButton);
	glutMotionFunc(handleMouseMove);

	glutMainLoop();
	return 0;
}