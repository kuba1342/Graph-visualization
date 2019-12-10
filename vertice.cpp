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
	ofDrawBitmapString(_id, _x - 3, _y + 3);
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
	if (weightBool)
		ofDrawBitmapString(std::to_string(_weight), _x - 45, _y - 15);
	else 
		ofDrawBitmapString(defaultWeight, _x - 45, _y - 15);
}

void vertice::setColor(ofColor color) {
	_color = color;
}

void vertice::setStringColor(ofColor color) {
	_stringColor = color;
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

bool vertice::getWeightBool() {
	return weightBool;
}

std::string vertice::getId() {
	return _id;
}

vertice::~vertice()
{
}
