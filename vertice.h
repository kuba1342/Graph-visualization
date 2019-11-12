#include <string>
#include "ofGraphics.h"



#pragma once
class vertice {
	std::string _id;
	double _x;
	double _y;

public:
	vertice();

	vertice(std::string id, double x, double y);

	void setup(std::string id, double x, double y);

	void draw();

	~vertice();
};

