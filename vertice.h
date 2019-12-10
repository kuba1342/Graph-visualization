#include <string>
#include "ofGraphics.h"



#pragma once
class vertice {
	std::string _id;
	double _x;
	double _y;
	int _weight = 0;
	std::string defaultWeight = "INF";
	bool weightBool = false;
	ofColor _color;
	ofColor _stringColor = ofColor(0, 0, 0);

public:
	vertice();

	vertice(std::string id, double x, double y);

	void setup(std::string id, double x, double y);

	void draw();

	void drawBFS();

	void drawWeight();

	void setColor(ofColor color);

	void setStringColor(ofColor color);

	void setWeight(int weight);

	int getX();

	int getY();

	int getWeight();

	bool getWeightBool();

	std::string getId();

	~vertice();
};

