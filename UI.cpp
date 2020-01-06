#include "UI.h"

UI::UI()
{
}

void UI::setup(int newMode) {
	mode = newMode;
}

void UI::draw() {
	glm::vec3 p;      
	p.x = (ofGetWidth() / 1) - 250;
	p.y = 0;

	// Background
	ofSetColor(255, 255, 255);
	ofDrawRectangle(p, 250, ofGetHeight());
	ofSetColor(0, 0, 0);

	ofDrawBitmapString("CURRENT MODE: " + displayMode, p.x + 10, 50);
	ofDrawBitmapString("MANUAL: " + manual, p.x + 10, 70);

	ofDrawBitmapString("SIZE:", p.x + 10, 120);
	ofDrawBitmapString("3X3 - F3", p.x + 10, 140);
	ofDrawBitmapString("4X4 - F4", p.x + 10, 160);
	ofDrawBitmapString("CUSTOM - F5", p.x + 10, 180);

	if (mode != 3) {
		ofSetColor(255, 0, 0);
		ofDrawCircle(p.x + 30, 230, 20);
		ofSetColor(0, 0, 0);
		ofDrawBitmapString("- VISITED", p.x + 60, 235);

		if (mode == 2) {
			ofSetColor(0, 160, 0);
			ofDrawCircle(p.x + 30, 280, 20);
			ofSetColor(0, 0, 0);
			ofDrawBitmapString("- FINAL PATH", p.x + 60, 285);
		}

		ofSetColor(255, 255, 0);
		ofDrawCircle(p.x + 30, 330, 20);
		ofSetColor(0, 0, 0);
		ofDrawBitmapString("- LAST VERTICE", p.x + 60, 335);

		ofSetColor(128, 0, 128);
		ofDrawCircle(p.x + 30, 380, 20);
		ofSetColor(0, 0, 0);
		ofDrawBitmapString("- CURRENT VERTICE", p.x + 60, 385);
	}
	else {
		ofSetColor(255, 0, 0);
		ofDrawCircle(p.x + 30, 230, 20);
		ofSetColor(0, 0, 0);
		ofDrawBitmapString("- NEW WEIGHT", p.x + 60, 235);

		ofSetColor(0, 255, 0);
		ofDrawCircle(p.x + 30, 280, 20);
		ofSetColor(0, 0, 0);
		ofDrawBitmapString("- VISITED", p.x + 60, 285);

		ofSetColor(0, 100, 255);
		ofDrawCircle(p.x + 30, 330, 20);
		ofSetColor(0, 0, 0);
		ofDrawBitmapString("- LAST VERTICE", p.x + 60, 335);

		ofSetColor(128, 0, 128);
		ofDrawCircle(p.x + 30, 380, 20);
		ofSetColor(0, 0, 0);
		ofDrawBitmapString("- CURRENT VERTICE", p.x + 60, 385);
	}

	ofDrawBitmapString("SWITCH MANUAL - LEFT ALT ", p.x + 10, 450);
	ofDrawBitmapString("NEXT STEP - LEFT SHIFT ", p.x + 10, 470);

	ofDrawBitmapString("SWITCH MODE - TAB", p.x + 10, 500);
	ofDrawBitmapString("RESET - RMB", p.x + 10, 520);
}

void UI::checkMode(int newMode) {
	mode = newMode;

	if (mode == 0)
		displayMode = "BFS";
	if (mode == 1)
		displayMode = "BFS PATH";
	if (mode == 2)
		displayMode = "DFS";
	if (mode == 3)
		displayMode = "Dijkstra";
}

void UI::checkManual(bool manualStatus) {
	if (manualStatus)
		manual = "ON";
	else
		manual = "OFF";
}

UI::~UI()
{
}
