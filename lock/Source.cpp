#include<GL\glew.h>
#include<GL\glut.h>
#include <iostream>
#include<math.h>
#include"drawer.h"

class cypher {

};

void display() {
	drawText("LOCK",L_PADD,.7, 1, 2);
	drawText("------------------------------------------", L_PADD, .65, 3, 2);

}

void renderScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	display();
	glutSwapBuffers();
}

int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WIN_H, WIN_W);
	glutCreateWindow("LOCK");
	
	glutDisplayFunc(renderScene);
	glutMainLoop();
	return 0;
}
