#include "ofApp.h"
#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>

//--------------------------------------------------------------
void ofApp::setup(){
	vertice = 0;

	graph.setup(9, 12);

	createGraphThree();

	//graph.DFS(0, G2, graph.getV(), pathToDraw);
}

//--------------------------------------------------------------
void ofApp::update(){
	float now = ofGetElapsedTimef();
	if (now > nextEventSeconds) {
		if (!executing) {			
			if (mode == 0) {
				for (int i = 0; i < visitedToDraw.size(); i++)
					vertices[visitedToDraw[i]].setColor(ofColor(0, 160, 0));
			}
			if (mode == 2 || mode == 1) {
				for (int i = 0; i < pathToDraw.size(); i++) 
					vertices[pathToDraw[i]].setColor(ofColor(0, 160, 0));
			}
			
			visitedToDraw.clear();
			pathToDraw.clear();
		}
		else {
			if (mode != 2) {
				vertices[visitedToDraw[vertice]].setColor(ofColor(255, 0, 0));
				if (vertice < visitedToDraw.size() - 1) {
					vertice++;
				}
				else
					executing = false;
			}

			if (mode == 2) {
				vertices[pathToDraw[vertice]].setColor(ofColor(255, 0, 0));
				if (vertice < pathToDraw.size() - 1) {
					vertice++;
				}
				else
					executing = false;
			}

		}
		nextEventSeconds = now + 3;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < vertices.size(); i++) {
		for (int j = 0; j < G2[i].size(); j++) {
			ofDrawLine(vertices[i].getX(), vertices[i].getY(), vertices[G2[i][j]].getX(), vertices[G2[i][j]].getY());
		}	
	}
	for (int x = 0; x < vertices.size(); x++)
		vertices[x].draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_F3 && !executing) {
		createGraphThree();
		reset();
	}

	if (key == OF_KEY_F4 && !executing) {
		createGraphFour();
		reset();
	}

	if (key == OF_KEY_TAB && !executing) {
		changeMode();
		std::cout << pathMode << std::endl;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == 0) {
		for (int i = 0; i < vertices.size(); i++) {
			int verticeX = vertices[i].getX();
			int verticeY = vertices[i].getY();
			if ((x >= (verticeX - 10) && x <= (verticeX + 10)) && (y >= (verticeY - 10) && y <= (verticeY + 10))) {
				if (!executing) {
					if (!startSelected) {
						start = std::stoi(vertices[i].getId());
						std::cout << "Start: " << start << std::endl;
						vertices[i].setColor(ofColor(0, 0, 255));
						startSelected = true;

						if (mode == 0) {
							graph.BFS(start, G2, graph.getV(), visitedToDraw);
						}

						if (mode == 2) {
							graph.DFS(start, G2, graph.getV(), pathToDraw);
						}
					}
					else {
						if (start != std::stoi(vertices[i].getId())) {
							destination = std::stoi(vertices[i].getId());
							std::cout << "Destination: " << destination << std::endl;
							vertices[i].setColor(ofColor(0, 0, 255));
							destinationSelected = true;
							graph.BFSPath(G2, start, destination, graph.getV(), visitedToDraw, pathToDraw);
						}
					}
					if (destinationSelected || (!pathMode && startSelected))
						executing = true;
				}
			}
		}
	}

	if (button == 2) {
		reset();
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

void ofApp::delay(int number_of_seconds) {
	// Converting time into milli_seconds 
	int milli_seconds = 1000 * number_of_seconds;

	// Stroing start time 
	clock_t start_time = clock();

	// looping till required time is not acheived 
	while (clock() < start_time + milli_seconds)
		;
}

void ofApp::reset() {
	if (!executing) {
		if (mode == 0) {
			pathMode = false;
			for (int i = 0; i < vertices.size(); i++) {
				vertices[i].setColor(ofColor(0, 0, 0));
				vertices[i].setStringColor(ofColor(255, 255, 255));
			}
		}
		if (mode == 1) {
			pathMode = true;
			for (int i = 0; i < vertices.size(); i++) {
				vertices[i].setColor(ofColor(255, 255, 255));
				vertices[i].setStringColor(ofColor(0, 0, 0));
			}
		}

		if (mode == 2) {
			pathMode = false;
			for (int i = 0; i < vertices.size(); i++) {
				vertices[i].setColor(ofColor(0, 0, 200));
				vertices[i].setStringColor(ofColor(255, 255, 255));
			}
		}

		vertice = 0;
		startSelected = false;
		destinationSelected = false;
		for (int i = 0; i < graph.getV(); i++) {
			graph.visited[i] = false;
		}
	}
}

void ofApp::changeMode() {
	reset();

	mode++;
	if (mode > 2)
		mode = 0;

	std::cout << mode << " ";

	if (mode == 0) {
		pathMode = false;
		for (int i = 0; i < vertices.size(); i++) {
			vertices[i].setColor(ofColor(0, 0, 0));
			vertices[i].setStringColor(ofColor(255, 255, 255));
		}
	}
	if (mode == 1) {
		pathMode = true;
		for (int i = 0; i < vertices.size(); i++) {
			vertices[i].setColor(ofColor(255, 255, 255));
			vertices[i].setStringColor(ofColor(0, 0, 0));
		}
	}

	if (mode == 2) {
		pathMode = false;
		for (int i = 0; i < vertices.size(); i++) {
			vertices[i].setColor(ofColor(0, 0, 200));
			vertices[i].setStringColor(ofColor(255, 255, 255));
		}
	}
}

void ofApp::createGraphFour(){
	G2.clear();
	G2.assign(24, std::vector<int>());

	graph.edge(0, 1, G2);
	graph.edge(1, 2, G2);
	graph.edge(2, 3, G2);
	graph.edge(0, 4, G2);
	graph.edge(1, 5, G2);
	graph.edge(2, 6, G2);
	graph.edge(3, 7, G2);
	graph.edge(4, 5, G2);
	graph.edge(5, 6, G2);
	graph.edge(6, 7, G2);
	graph.edge(4, 8, G2);
	graph.edge(5, 9, G2);
	graph.edge(6, 10, G2);
	graph.edge(7, 11, G2);
	graph.edge(8, 9, G2);
	graph.edge(9, 10, G2);
	graph.edge(10, 11, G2);
	graph.edge(8, 12, G2);
	graph.edge(9, 13, G2);
	graph.edge(10, 14, G2);
	graph.edge(11, 15, G2);
	graph.edge(12, 13, G2);
	graph.edge(13, 14, G2);
	graph.edge(14, 15, G2);

	graph.setV(16);
	graph.visited.assign(graph.getV(), false);

	vertices.resize(graph.getV());

	int x = 100;
	int y = 100;
	int loopCounter = 0;

	for (int i = 0; i < graph.getV(); i++) {
		vertices[i].setup(std::to_string(i), x, y);
		x += 200;
		loopCounter += 1;
		if (loopCounter == 4) {
			x = 100;
			y += 200;
			loopCounter = 0;
		}
	}
}

void ofApp::createGraphThree() {
	G2.clear();
	G2.assign(12, std::vector<int>());

	graph.visited.assign(graph.getV(), false);

	graph.edge(0, 1, G2);
	graph.edge(0, 3, G2);
	graph.edge(1, 2, G2);
	graph.edge(1, 4, G2);
	graph.edge(2, 5, G2);
	graph.edge(3, 4, G2);
	graph.edge(3, 6, G2);
	graph.edge(4, 5, G2);
	graph.edge(4, 7, G2);
	graph.edge(5, 8, G2);
	graph.edge(6, 7, G2);
	graph.edge(7, 8, G2);

	graph.setV(9);
	vertices.resize(graph.getV());

	int x = 100;
	int y = 100;
	int loopCounter = 0;

	for (int i = 0; i < graph.getV(); i++) {
		vertices[i].setup(std::to_string(i), x, y);
		x += 300;
		loopCounter += 1;
		if (loopCounter == 3) {
			x = 100;
			y += 300;
			loopCounter = 0;
		}
	}
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
