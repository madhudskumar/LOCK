#pragma once

#include<string>

#define WIN_H 800
#define WIN_W 600
#define R_PADD 0.1
#define L_PADD -0.8
#define MSG "Attempts left : "





GLfloat color[4][3] = {
	{1.0,0,0},				//r
	{0,1.0,0},				//g
	{0,0,1.0},				//b
	{1,1,1}					//w
};


void drawRectangle(GLfloat ver[2][2], int cc) {
	glColor3fv(color[cc]);
	glRectf(ver[0][0], ver[0][1], ver[1][0], ver[1][1]);
}

void drawTriangle(GLfloat ver[3][2] , int cc) {
	glColor3fv(color[cc]);
	glBegin(GL_TRIANGLES);
	glVertex2f(ver[0][0], ver[0][1]);
	glVertex2f(ver[1][0], ver[1][1]);
	glVertex2f(ver[2][0], ver[2][1]);
	glEnd();
}

void drawText(const char *txt, GLfloat x, GLfloat y, int cc,int size) {
	void *font;
	switch (size) {
	case 1: font = GLUT_BITMAP_HELVETICA_12; 
		break;
	case 2: font = GLUT_BITMAP_HELVETICA_18;
		break;
	default: font = GLUT_BITMAP_HELVETICA_10;
		break;
	}
	const char *c;
	glColor3fv(color[cc]);
	glRasterPos2f(x, y);
	for (c = txt; *c != '\0'; c++)
		glutBitmapCharacter(font, *c);
}

void attemptSwitch(int attp, GLfloat x, GLfloat y, int cc, int size) {
	switch (attp) {
	case 1:drawText("1", x, y, cc, size);
		break;
	case 2:drawText("2", x, y, cc, size);
		break;
	case 3:drawText("3", x, y, cc, size);
		break;
	case 4:drawText("4", x, y, cc, size);
		break;
	case 5:drawText("5", x, y, cc, size);
		break;
	}
}