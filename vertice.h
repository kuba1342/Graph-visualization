#include <string>
#include "ofGraphics.h"



#pragma once
class vertice {
	std::string _id;
	double _x;
	double _y;
	int _weight = INT_MAX;
	std::string defaultWeight = "INF";
	bool weightBool = false;
	bool visited = false;
	bool dijkstra = false;
	ofColor _color;
	ofColor _stringColor = ofColor(0, 0, 0);
	ofColor _weightColor = ofColor(0, 0, 0);

public:
	vertice();

	vertice(std::string id, double x, double y);

	void setup(std::string id, double x, double y);

	void draw();

	void drawBFS();

	void drawWeight();

	void setColor(ofColor color);

	void setStringColor(ofColor color);

	void setWeightColor(ofColor color);

	void setWeight(int weight);

	int getX();

	int getY();

	int getWeight();

	void setWeightBool(bool weight);

	bool getWeightBool();

	void setVisited(bool newStatus);

	bool getVisited();

	void setDijkstra(bool dijkstraState);

	bool getDijkstra();

	std::string getId();

	~vertice();
};

