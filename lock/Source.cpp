#include<GL\glew.h>
#include<GL\glut.h>
#include <iostream>
#include<math.h>
#include<string>
#include"drawer.h"

using namespace std;

int lp_ct = 5;

char *status = "LOCKED";


GLfloat t_1[3][2] = {
	{ -.7, 0.2 },	//top
	{ -.8, 0 },		//left
	{ -.6, 0 }		//right
};

GLfloat t_2[3][2] = {
	{ -.48, 0.2 },	//top
	{ -.58, 0 },	//left
	{ -.38, 0 }		//right
};

GLfloat t_3[3][2] = {
	{ (-.7 + .44), 0.2 },	//top
	{ (-.8 + .44), 0 },		//left
	{ (-.6 + .44), 0 }		//right
};

GLfloat t_4[3][2] = {
	{ (-.7 + .66), 0.2 },	//top
	{ (-.8 + .66), 0 },		//left
	{ (-.6 + .66), 0 }		//right
};

GLfloat go[3][2] = {
	{.1, -.3},
	{.1,-.05},
	{.3, -.16}
};

GLfloat s_1[2][2] = {
	{-.8, -0.05},
	{-.6,-.3}
};

GLfloat s_2[2][2] = {
	{ -0.58, -0.05 },
	{ -.38,-.3 }
};

GLfloat s_3[2][2] = {
	{ (-.8 + .44), -0.05 },
	{ (-.6 + .44),-.3 }
};


GLfloat s_4[2][2] = {
	{ (-.8 + .66), -0.05 },
	{ (-.6 + .66),-.3 }
};

GLfloat wrong[2][2] = {
	{-.8,-.5},
	{-.7,-.4}
};

GLfloat iPlacement[2][2] = {
	{ -.8,-.61 },
	{ -.7,-.51 }
};

class cypher {

};



void display() {
	//Header
	drawText(status,L_PADD,.7, 1, 2);
	drawText("------------------------------", L_PADD, .65, 3, 2);
	
	drawText(MSG, R_PADD, .6, 0, 0);
	attemptSwitch(lp_ct, R_PADD + .19, .6, 1, 2);

	//Body
	//>triangles
	drawTriangle(t_1, 6);
	drawTriangle(t_2, 6);
	drawTriangle(t_3, 6);
	drawTriangle(t_4, 6);
	
	//>sqiares
	drawRectangle(s_1, 4);
	drawRectangle(s_2, 4);
	drawRectangle(s_3, 4);
	drawRectangle(s_4, 4);

	//text

	//>go
	drawTriangle(go, 1);
	//footer
	drawRectangle(wrong, 0);
	drawText("wrong input", L_PADD + .12, -.46, 3, 0);
	
	drawRectangle(iPlacement, 8);
	drawText("wrong placement", L_PADD + .12, -.57, 3, 0);


}

void renderScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	display();
	glutSwapBuffers();
}

void myFunc(int button, int state,int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && status == "LOCKED") {
		status = "UNLOCKED";
		glutPostRedisplay();
	}else{
		status = "LOCKED";
		glutPostRedisplay();
	}
}

int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WIN_H, WIN_W);
	glutCreateWindow("LOCK");
	

	glutMouseFunc(myFunc);
	glutDisplayFunc(renderScene);
	glutMainLoop();
	return 0;
}
