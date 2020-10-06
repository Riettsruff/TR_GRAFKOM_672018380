#include <GL/freeglut.h>
#include "KapalPesiar.h"

// TOPIC
// Kapal Pesiar - Oasis Of The Seas

// CONTRIBUTOR
// - Rietts Andreas Ruff       672018380
// - Yehezkiel Yeremy Rampen   672018429 

KapalPesiar oasisOfTheSeas;

void handleMouseButtonWrapper(int button, int state, int x, int y) {
	oasisOfTheSeas.handleMouseButton(button, state, x, y);
}

void handleMouseMoveWrapper(int x, int y) {
	oasisOfTheSeas.handleMouseMove(x, y);
}

void handleKeyboardWrapper(unsigned char key, int x, int y) {
	oasisOfTheSeas.handleKeyboard(key, x, y);
}

void reshapeWrapper(int w, int h) {
	oasisOfTheSeas.reshape(w, h);
}

void displayWrapper() {
	oasisOfTheSeas.display();
}

void handleTimerWrapper(int x) {
	oasisOfTheSeas.handleTimer(x);
	glutTimerFunc(600, handleTimerWrapper, 0);
}

void myInit() {
	glClearColor(0.5, 0.2, 0.8, 1.0);
	glLineWidth(2);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 600);
	glutCreateWindow("KAPAL PESIAR - OASIS OF THE SEAS");
	myInit();
	glutDisplayFunc(displayWrapper);
	glutReshapeFunc(reshapeWrapper);
	glutKeyboardFunc(handleKeyboardWrapper);
	glutMouseFunc(handleMouseButtonWrapper);
	glutMotionFunc(handleMouseMoveWrapper);
	glutTimerFunc(600, handleTimerWrapper, 0);

	glutMainLoop();
	return 0;
}
