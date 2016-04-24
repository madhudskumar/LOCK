#include<math.h>
#include<random>
#include<iostream>
#include<time.h>

#pragma once

typedef struct cypher {
	int h = 0;
	int t = 0;
	int u = 0;
};

int genRandy() {
	srand(time(NULL));
	return (rand()) % 1000;
}

int genCypher() {
	int rand = genRandy();
	
	while (rand < 100)
		rand = genRandy();


	cout << rand;
	return rand;
}

cypher checkCyphers(cypher headObj, cypher obj, int *s1, int *s2, int *s3) {
	cypher flag;
	
	//hundreds
	if (headObj.h == obj.h) {
		flag.h = 1;
		*s1 = 1;
	}
	else if ((obj.h == headObj.t) || (obj.h == headObj.u)) {
		*s1 = 8;
	}else {
		*s1 = 0;
	}

	//tens
	if (headObj.t == obj.t) {
		flag.t = 1;
		*s2 = 1;
	}
	else if ((obj.t == headObj.h) || (obj.t == headObj.u)) {
		*s2 = 8;
	}
	else {
		*s2 = 0;
	}

	//units
	if (headObj.u == obj.u) {
		flag.u = 1;
		*s3 = 1;
	}
	else if ((obj.u == headObj.t) || (obj.u == headObj.h)) {
		*s3 = 8;
	}
	else {
		*s3 = 0;
	}

	return flag;
}