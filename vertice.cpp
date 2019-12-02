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
	//ofNoFill();
	//ofColor black(0, 0, 0);
	ofSetColor(_color);
	ofDrawCircle(_x, _y, 20);
	ofSetColor(ofColor(0, 0, 0));
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

void vertice::setColor(ofColor color) {
	_color = color;
}

int vertice::getX(){
	return _x;
}

int vertice::getY() {
	return _y;
}

std::string vertice::getId() {
	return _id;
}

vertice::~vertice()
{
}
