#include <GL/freeglut.h>
#include "blue_object.h"
#include "dark_brown_object.h"
#include "dark_grey_object.h"
#include "grey_object.h"
#include "smooth_blue_object.h"
#include "smooth_brown_object.h"
#include "smooth_grey_object.h"
#include "super_dark_brown_object.h"
#include "white_object.h"
#include "yellow_object.h"

class KapalPesiar {
	float xrot = 0;
	float yrot = 0;
	float xdiff = 0;
	float ydiff = 0;
	bool mousedown = false;
	bool isColorOneActive = false;

	public:
		void handleMouseButton(int button, int state, int x, int y) {
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
				mousedown = true;
				xdiff = x - yrot;
				ydiff = -y + xrot;
			} else {
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

		void handleTimer(int) {
			isColorOneActive = !isColorOneActive;
			glutPostRedisplay();
		}

		void display() {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glPushMatrix();
			gluLookAt(0, 70, -350, 0, 0, 0, 0, 1, 0);
			glRotatef(xrot, 1, 0, 0);
			glRotatef(yrot, 0, 1, 0);

			if (isColorOneActive) glClearColor(0.3, 0.1, 0.5, 1.0);
			else glClearColor(0.3, 0.2, 0.6, 1.0);

			blueObject();
			darkBrownObject();
			darkGreyObject();
			greyObject();
			smoothBlueObject();
			smoothBrownObject();
			smoothGreyObject();
			superDarkBrownObject();
			whiteObject();
			yellowObject();

			glPopMatrix();
			glutSwapBuffers();
		}
};