#include<GL\glew.h>
#include<GL\glut.h>
#include <iostream>
#include<math.h>
#include<string>
#include"drawer.h"
#include"ray.h"
#include"cypher.h"

using namespace std;

int lp_ct = 5;

char *status = "LOCKED";

int t_1_c, t_2_c, t_3_c, g_c;

int h_c, t_c, u_c;

int s1_c, s2_c, s3_c;

void initColors() {
	t_1_c = t_2_c = t_3_c = 6;
	g_c = 1;
}

void initTextCol() {
	h_c = t_c = u_c = 9;
	s1_c = s2_c = s3_c = 4;
}

struct flags {
	int attemt_valid = 1;
	int locked = 1;
}disp_flag;

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

GLfloat go[3][2] = {
	{.4, -.3},
	{.4,-.05},
	{.6, -.16}
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


GLfloat wrong[2][2] = {
	{-.8,-.5},
	{-.7,-.4}
};

GLfloat iPlacement[2][2] = {
	{ -.8,-.61 },
	{ -.7,-.51 }
};

cypher obj;
cypher headObj;

void display() {
	if (disp_flag.attemt_valid && disp_flag.locked) {
		//Header
		drawText(status, L_PADD, .7, 1, 2);
		drawText("------------------------------", L_PADD, .65, 3, 2);

		drawText(MSG, R_PADD, .6, 0, 0);
		drawAttemptSwitch(lp_ct, R_PADD + .19, .6, 1, 2);

		//Body
		//>triangles
		drawTriangle(t_1, t_1_c);
		drawTriangle(t_2, t_2_c);
		drawTriangle(t_3, t_3_c);
		initColors();
		//>sqiares
		drawRectangle(s_1, s1_c);
		drawRectangle(s_2, s2_c);
		drawRectangle(s_3, s3_c);
		//>text
		drawAttemptSwitch(obj.h, -.65, -.28, h_c, 2);
		drawAttemptSwitch(obj.t, -.65 + .22, -.28, t_c, 2);
		drawAttemptSwitch(obj.u, -.65 + .44, -.28, u_c, 2);
		//>go
		drawTriangle(go, g_c);

		//footer
		drawRectangle(wrong, 0);
		drawText("wrong input", L_PADD + .12, -.46, 3, 0);

		drawRectangle(iPlacement, 8);
		drawText("wrong placement", L_PADD + .12, -.57, 3, 0);
	}
	else if (!disp_flag.attemt_valid) {
		drawText("GAME OVER", -.5, 0, 0, 2);
	}
	else if (!disp_flag.locked) {
		drawText("YOU UNLOCKED", -.5, 0, 1, 2);
	}
	
}

void renderScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	display();
	glutSwapBuffers();
}

void calcHeadCypher() {
	int head = genCypher();
	headObj.h = (int)(head / 100);
	headObj.t = (int)((head % 100) / 10);
	headObj.u = (int)(head % 10);
	cout << headObj.h << " " << headObj.t << " " << headObj.u << endl; 
}

void myFunc(int button, int state,int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && status == "LOCKED") {
		if (calcHit(1, x, y)) {
			t_1_c = 5;
			obj.h++;
			obj.h %= 10;
			glutPostRedisplay();
		}
		else if (calcHit(2, x, y)) {
			t_2_c = 5;
			obj.t++;
			obj.t %= 10;
			glutPostRedisplay();
		}
		else if (calcHit(3, x, y)) {
			t_3_c = 5;
			obj.u++;
			obj.u %= 10;
			glutPostRedisplay();
		}
		else if (calcHit(5, x, y)) {
			if ((lp_ct--) == 0) {
				disp_flag.attemt_valid = 0;
				glutPostRedisplay();
				return;
			}
			cypher flag = checkCyphers(headObj, obj, &s1_c, &s2_c, &s3_c);
			g_c = 6;
			if (flag.h == 1 && flag.t == 1 && flag.u == 1) {
				disp_flag.locked = 0;
			}
			glutPostRedisplay();
		}

	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WIN_H, WIN_W);
	glutCreateWindow("LOCK");
	glutMouseFunc(myFunc);
	initColors();
	initTextCol();
	calcHeadCypher();
	glutDisplayFunc(renderScene);
	glutMainLoop();
	return 0;
}
