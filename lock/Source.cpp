#include<GL\glew.h>
#include<GL\glut.h>
#include <iostream>
#include<math.h>
#include<string>
#include"drawer.h"

using namespace std;

int lp_ct = 5;


GLfloat t_1[3][2] = {
	{ 0,0.5 },
	{ -.5,-.5 },
	{ 0.5,-.5 }
};

GLfloat t_2[3][2] = {
	{ 0,0.5 },
	{ -.5,-.5 },
	{ 0.5,-.5 }
};

GLfloat t_3[3][2] = {
	{ 0,0.5 },
	{ -.5,-.5 },
	{ 0.5,-.5 }
};

GLfloat s_1[2][2] = {
	{0,0},
	{.5,.5}
};

GLfloat s_2[2][2] = {
	{ 0,0 },
	{ .5,.5 }
};

GLfloat s_3[2][2] = {
	{ 0,0 },
	{ .5,.5 }
};

class cypher {

};



void display() {
	//Header
	drawText("LOCK",L_PADD,.7, 1, 2);
	drawText("------------------------------------------", L_PADD, .65, 3, 2);
	
	drawText(MSG, R_PADD, .6, 0, 0);
	attemptSwitch(lp_ct, R_PADD + .19, .6, 1, 2);

	//Body
	drawTriangle(t_1, 1);
	drawRectangle(s_1, 2);
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
