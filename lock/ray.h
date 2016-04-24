#include<math.h>
#include<iostream>
#include<Windows.h>
#include<GL\glew.h>
#include<GL\glut.h>

#pragma once

using namespace std;

struct point {
	float x;
	float y;
};

int tr_1[3][2] = {
	{7,2},
	{4,3},
	{3,2}
};

int tr_2[3][2] = {
	{ 3,2 },
	{ 2,3 },
	{ 2,2 }
};

int tr_3[3][2] = {
	{ 2,2 },
	{ 1,3 },
	{ 1,2 }
};

int tr_4[3][2] = {
	{ 1,2 },
	{ 1,3 },
	{ 1,2 }
};

int go_c[3][2] = {
	{ 0,2 },
	{ 0,0 },
	{ 0,2 }
};

point normalizeToDevice(int mouseX, int mouseY);
bool checkValid(int tri[3][2], point cor);

bool calcHit(int ch, int mouseX, int mouseY) {
	point cor = normalizeToDevice(mouseX, mouseY);
	switch (ch)
	{
	case 1:
		if (checkValid(tr_1, cor)) { 
			std::cout << "HIT 1" << endl;
			return true; 
		}
		break;
	case 2:
		if (checkValid(tr_2, cor)) {
			std::cout << "HIT 2" << endl;
			return true;
		}
		break;
	case 3:
		if (checkValid(tr_3, cor)) {
			std::cout << "HIT 3" << endl;
			return true;
		}
		break;
	default:
		if (checkValid(go_c, cor)) {
			std::cout << "HIT go" << endl;
			return true;
		}
		break;
	}
}

point normalizeToDevice(int mouseX, int mouseY) {
	float x = WIN_W / mouseX;
	float y = WIN_H / mouseY;
	std::cout << "x : " << x << endl;
	std::cout << "y : " << y << endl << endl;
	point cor;
	cor.x = x;
	cor.y = y;
	return cor;
}

bool checkValid(int tri[3][2], point cor) {
	cout << tri[0][0] << " " << tri[0][1] << endl;
	cout << tri[1][0] << " " << tri[1][1] << endl;
	cout << tri[2][0] << " " << tri[2][1] << endl << endl;
	return !!((cor.x >= tri[0][0] && cor.y >= tri[0][1]) || (cor.x >= tri[1][0] && cor.y >= tri[1][1]) || (cor.x >= tri[2][0] && cor.y >= tri[2][1]));
}