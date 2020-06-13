#include <iostream>
#include <GL/glut.h>

void render();
void special(int key, int x, int y);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv) {

	std::cout <<
		std::endl <<
		"GLUT Rotating Cube" <<
		std::endl <<
		"Use arrow keys to rotate the cube" <<
		std::endl <<
		"Press Esc to exit" <<
		std::endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 640);
	glutCreateWindow("GLUT Rotating Cube");

	glutDisplayFunc(render);
	glutSpecialFunc(special);
	glutKeyboardFunc(keyboard);

	glRotatef(30, 1, 0, 0);
	glRotatef(-45, 0, 1, 0);

	glutMainLoop();

}

void render() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_LINES);
		glVertex3f(-0.5, 0.5, 0.5);
		glVertex3f(0.5, 0.5, 0.5);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0.5, 0.5, 0.5);
		glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0.5, -0.5, 0.5);
		glVertex3f(-0.5, -0.5, 0.5);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-0.5, -0.5, 0.5);
		glVertex3f(-0.5, 0.5, 0.5);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(-0.5, 0.5, -0.5);
		glVertex3f(0.5, 0.5, -0.5);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0.5, 0.5, -0.5);
		glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0.5, -0.5, -0.5);
		glVertex3f(-0.5, -0.5, -0.5);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-0.5, -0.5, -0.5);
		glVertex3f(-0.5, 0.5, -0.5);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(0.5, 0.5, 0.5);
		glVertex3f(0.5, 0.5, -0.5);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-0.5, 0.5, 0.5);
		glVertex3f(-0.5, 0.5, -0.5);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0.5, -0.5, 0.5);
		glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-0.5, -0.5, 0.5);
		glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	glutSwapBuffers();

}

void special(int key, int x, int y) {
	const int rotateAngle = 2;
	switch (key) {
		case GLUT_KEY_UP:
			glRotatef(-rotateAngle, 1, 0, 0);
			break;
		case GLUT_KEY_DOWN:
			glRotatef(rotateAngle, 1, 0, 0);
			break;
		case GLUT_KEY_LEFT:
			glRotatef(-rotateAngle, 0, 1, 0);
			break;
		case GLUT_KEY_RIGHT:
			glRotatef(rotateAngle, 0, 1, 0);
			break;
		default:
			return;
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 27) exit(0);
}
