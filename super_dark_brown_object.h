#include <GL/freeglut.h>

void superDarkBrownObject() {
	glColor3ub(146, 82, 28);

	glBegin(GL_POLYGON);
	glVertex3d(-9.772309, 56.181091, -103.20401);
	glVertex3d(8.449821, 39.164795, -103.740005);
	glVertex3d(-9.772309, 39.164795, -103.20401);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(8.449821, 39.164795, -103.740005);
	glVertex3d(-9.772309, 56.181091, -103.20401);
	glVertex3d(8.449821, 56.181091, -103.740005);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(8.449821, 56.181091, -103.740005);
	glVertex3d(-9.772309, 56.181091, -103.20401);
	glVertex3d(8.449821, 39.164795, -103.740005);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(-9.772309, 39.164795, -103.20401);
	glVertex3d(8.449821, 39.164795, -103.740005);
	glVertex3d(-9.772309, 56.181091, -103.20401);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(-4.4007, 43.145203, 62.841099);
	glVertex3d(11.282499, 17.9384, 62.380093);
	glVertex3d(-4.4007, 17.9384, 62.841099);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(11.282499, 17.9384, 62.380093);
	glVertex3d(-4.4007, 43.145203, 62.841099);
	glVertex3d(11.282499, 43.145203, 62.380093);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(11.282499, 43.145203, 62.380093);
	glVertex3d(-4.4007, 43.145203, 62.841099);
	glVertex3d(-4.4007, 46.061096, 62.841099);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(11.282499, 43.145203, 62.380093);
	glVertex3d(-4.4007, 46.061096, 62.841099);
	glVertex3d(11.282499, 46.061096, 62.380093);
	glEnd();
}