#include "vertice.h"



vertice::vertice()
{
}

vertice::vertice(std::string id, double x, double y) {
	_id = id;
	_x = x;
	_y = y;
}

void vertice::setup(std::string id, double x, double y) {
	_id = id;
	_x = x;
	_y = y;
}

void vertice::draw() {
	
	ofSetColor(_color);
	ofDrawCircle(_x, _y, 20);
	ofSetColor(ofColor(_stringColor));
	if (!dijkstra)
		ofDrawBitmapString(_id, _x - 3, _y + 3);
	else
		ofDrawBitmapString(_id, _x - 45, _y - 15);
	ofSetColor(0, 0, 0);
}

void vertice::drawBFS() {
	ofNoFill();
	ofColor red(255, 0, 0);
	ofSetColor(red);
	ofDrawCircle(_x, _y, 20);
	ofDrawBitmapString(_id, _x - 3, _y + 3);
	ofColor black(0, 0, 0);
	ofSetColor(black);
}

void vertice::drawWeight() {
	if (weightBool) {
		ofSetColor(_weightColor);
		// -45, -15
		ofDrawBitmapString(std::to_string(_weight), _x - 3, _y + 3);
		ofSetColor(ofColor(0, 0, 0));
	}
	else 
		ofDrawBitmapString(defaultWeight, _x - 3, _y - 3);
}


void vertice::setColor(ofColor color) {
	_color = color;
}

void vertice::setStringColor(ofColor color) {
	_stringColor = color;
}

void vertice::setWeightColor(ofColor color) {
	_weightColor = color;
}

void vertice::setWeight(int weight) {
	
	weightBool = true;
	_weight = weight;
}

int vertice::getX(){
	return _x;
}

int vertice::getY() {
	return _y;
}

int vertice::getWeight() {
	return _weight;
}

void vertice::setWeightBool(bool weight) {
	weightBool = weight;
}

bool vertice::getWeightBool() {
	return weightBool;
}

void vertice::setVisited(bool newStatus) {
	visited = newStatus;
}

bool vertice::getVisited() {
	return visited;
}

void vertice::setDijkstra(bool dijkstraState) {
	dijkstra = dijkstraState;
}

bool vertice::getDijkstra() {
	return dijkstra;
}

std::string vertice::getId() {
	return _id;
}

vertice::~vertice()
{
}
