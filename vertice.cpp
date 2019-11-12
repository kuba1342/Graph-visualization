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
	ofNoFill();
	ofDrawCircle(_x, _y, 20);
	ofDrawBitmapString(_id, _x - 3, _y + 3);
}

vertice::~vertice()
{
}
