#include <string>
#include "ofGraphics.h"



#pragma once
class vertice {
	std::string _id;
	double _x;
	double _y;
	ofColor _color;

public:
	vertice();

	vertice(std::string id, double x, double y);

	void setup(std::string id, double x, double y);

	void draw();

	void drawBFS();

	void setColor(ofColor color);

	int getX();

	int getY();

	std::string getId();

	~vertice();
};
