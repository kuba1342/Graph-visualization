#include "ofApp.h"
#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>

//--------------------------------------------------------------
void ofApp::setup(){
	ui.setup(mode);

	vertice = 0;

	graph.setup(9, 12);

	createGraphThree();
	
	//createGraph("test.txt");
}

//--------------------------------------------------------------
void ofApp::update(){
	ui.checkMode(mode);
	ui.checkManual(manual);

	if (!manual)
		manualOff();
	else
		manualOn();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ui.draw();

	for (int i = 0; i < vertices.size(); i++) {
		for (int j = 0; j < G2[i].size(); j++) {
			ofDrawLine(vertices[i].getX(), vertices[i].getY(), vertices[G2[i][j]].getX(), vertices[G2[i][j]].getY());
			if (mode == 3)
				graph.drawEdgeWeight(vertices[i], vertices[G2[i][j]], weightVector[i][G2[i][j]]);
		}	
	}
	for (int x = 0; x < vertices.size(); x++) {
		vertices[x].draw();
		if (mode == 3) {
			vertices[x].drawWeight();
			vertices[x].setDijkstra(true);
		}
		else
			vertices[x].setDijkstra(false);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_F3 && !executing) {
		if (mode != 3)
			createGraphThree();
		else
			createWeightGraphThree();

		reset();
	}

	if (key == OF_KEY_F4 && !executing) {
		if (mode != 3)
			createGraphFour();
		else
			createWeightGraphFour();

		reset();
	}

	if (key == OF_KEY_F5 && !executing) {
		createGraph("test.txt");
		reset();
	}

	if (key == OF_KEY_TAB && !executing) {
		changeMode();
		if (mode == 3)
			createWeightGraphThree();
		reset();
		std::cout << pathMode << std::endl;
	}

	if (key == OF_KEY_LEFT_ALT) {		// test with executing
		changeManual();
	}

	if (key == OF_KEY_LEFT_SHIFT) {
		nextStep();
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

						if (mode == 3) {
							//graph.BFS(start, G2, graph.getV(), visitedToDraw);
							//graph.prepareDijkstra();
							//count = 0;
							//current = start;
						}
					}
					else {
						if (start != std::stoi(vertices[i].getId())) {
							destination = std::stoi(vertices[i].getId());
							std::cout << "Destination: " << destination << std::endl;
							vertices[i].setColor(ofColor(0, 0, 255));
							destinationSelected = true;
							if (mode == 1)
								graph.BFSPath(G2, start, destination, graph.getV(), visitedToDraw, pathToDraw);
							if (mode == 3) {
							//	graph.BFS(start, G2, graph.getV(), visitedToDraw);
								graph.prepareDijkstra();
								count = 0;
								current = start;
							}
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

		for (int i = 0; i < vertices.size(); i++)
			vertices[i].setVisited(false);

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

		if (mode == 3) {
			pathMode = true;
			for (int i = 0; i < vertices.size(); i++) {
				vertices[i].setColor(ofColor(255, 255, 0));
				vertices[i].setStringColor(ofColor(0, 0, 0));
				vertices[i].setWeight(INT_MAX);
				vertices[i].setWeightBool(false);
			}
		}

		vertice = 0;
		startSelected = false;
		destinationSelected = false;
		for (int i = 0; i < graph.getV(); i++) {
			graph.visited[i] = false;
		}
		verticesWeight.clear();
	}
}

void ofApp::changeMode() {
	reset();

	mode++;
	if (mode > 3)
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

	if (mode == 3) {
		pathMode = false;
		for (int i = 0; i < vertices.size(); i++) {
			vertices[i].setColor(ofColor(255, 255, 0));
			vertices[i].setStringColor(ofColor(0, 0, 0));
		}
	}
}

void ofApp::changeManual() {
	if (manual)
		manual = false;
	else
		manual = true;
}

void ofApp::nextStep() {
	if (manual)
		if (mode != 3) {
			if (vertice < visitedToDraw.size() - 1) {
				vertice++;
			}
		}
		else
			doDijkstra();
}

void ofApp::doDijkstra() {
	if (mode == 3) {
		if (count < graph.getV()) {
			vertices[current].setColor(ofColor(128, 0, 128));
			verticesWeight = vertices;
			int previous = current;
			graph.Dijkstra(weightVector, start, graph.getDist(), graph.getSptSet(), vertices, current);
			vertices[current].setVisited(true);

			for (int i = 0; i < vertices.size(); i++) {
				if (verticesWeight[i].getWeight() != vertices[i].getWeight()) {
					if (i != current) 
						vertices[i].setColor(ofColor(255, 0, 0));
				}
				else {
					vertices[i].setWeightColor(ofColor(0, 0, 0));
					if (vertices[i].getVisited())
						if (i != current)
							vertices[i].setColor(ofColor(0, 255, 0));
						else {
							vertices[current].setColor(ofColor(128, 0, 128));
						}
					else
						if (i != current)
							vertices[i].setColor(ofColor(255, 255, 0));
				}
				if (i == previous)
					vertices[i].setColor(ofColor(0, 100, 255));
			}
			count++; 
			vertices[start].setColor(ofColor(230, 230, 230));
		}
		else {
			executing = false;

			if (mode == 3) {
				graph.printDijkstraPath(graph.getParent(), destination);
				for (int i = 0; i < graph.dijkstraPath.size(); i++) 
					vertices[graph.dijkstraPath[i]].setColor(ofColor(230, 230, 230));
			}
		}
	}
}

void ofApp::clearVectors() {
	visitedToDraw.clear();
	pathToDraw.clear();
}

void ofApp::manualOff() {
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

			clearVectors();
		}
		else {
			if (mode == 1 || mode == 0) {
				vertices[visitedToDraw[vertice]].setColor(ofColor(128, 0, 128));

				if (vertice > 0)
					vertices[visitedToDraw[vertice - 1]].setColor(ofColor(255, 255, 0));

				if (vertice > 1)
					vertices[visitedToDraw[vertice - 2]].setColor(ofColor(255, 0, 0));

				if (vertice < visitedToDraw.size() - 1) {
					vertice++;
				}
				else
					executing = false;
			}

			if (mode == 2) {
				vertices[pathToDraw[vertice]].setColor(ofColor(128, 0, 128));

				if (vertice > 0)
					vertices[pathToDraw[vertice - 1]].setColor(ofColor(255, 255, 0));

				if (vertice > 1)
					vertices[pathToDraw[vertice - 2]].setColor(ofColor(255, 0, 0));

				if (vertice < pathToDraw.size() - 1) {
					vertice++;
				}
				else
					executing = false;
			}
			doDijkstra();
		}
		nextEventSeconds = now + 3;
	}
}

void ofApp::manualOn() {
	if (!executing) {
		if (mode == 0) {
			for (int i = 0; i < visitedToDraw.size(); i++)
				vertices[visitedToDraw[i]].setColor(ofColor(0, 160, 0));
		}
		if (mode == 2 || mode == 1) {
			for (int i = 0; i < pathToDraw.size(); i++)
				vertices[pathToDraw[i]].setColor(ofColor(0, 160, 0));
		}

		clearVectors();
	}
	else {
		if (mode == 1 || mode == 0) {
			vertices[visitedToDraw[vertice]].setColor(ofColor(128, 0, 128));

			if (vertice > 0)
				vertices[visitedToDraw[vertice - 1]].setColor(ofColor(255, 255, 0));

			if (vertice > 1)
				vertices[visitedToDraw[vertice - 2]].setColor(ofColor(255, 0, 0));

			if (vertice < visitedToDraw.size() - 1) {
				
			}
			else
				executing = false;
		}

		if (mode == 2) {
			vertices[pathToDraw[vertice]].setColor(ofColor(128, 0, 128));

			if (vertice > 0)
				vertices[pathToDraw[vertice - 1]].setColor(ofColor(255, 255, 0));

			if (vertice > 1)
				vertices[pathToDraw[vertice - 2]].setColor(ofColor(255, 0, 0));

			if (vertice < pathToDraw.size() - 1) {
				
			}
			else
				executing = false;
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
	graph.setup(9, 12);

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

void ofApp::createWeightGraphFour() {
	G2.clear();
	G2.assign(24, std::vector<int>());
	graph.setup(16, 24);

	graph.setV(16);
	graph.visited.assign(graph.getV(), false);

	weightVector.assign(graph.getV(), std::vector<int>());
	for (int i = 0; i < weightVector.size(); i++) {
		weightVector[i].assign(graph.getV(), 0);
	}

	graph.weightEdge(0, 1, G2, 4, weightVector);
	graph.weightEdge(1, 2, G2, 5, weightVector);
	graph.weightEdge(2, 3, G2, 6, weightVector);
	graph.weightEdge(0, 4, G2, 7, weightVector);
	graph.weightEdge(1, 5, G2, 8, weightVector);
	graph.weightEdge(2, 6, G2, 9, weightVector);
	graph.weightEdge(3, 7, G2, 10, weightVector);
	graph.weightEdge(4, 5, G2, 11, weightVector);
	graph.weightEdge(5, 6, G2, 12, weightVector);
	graph.weightEdge(6, 7, G2, 13, weightVector);
	graph.weightEdge(4, 8, G2, 14, weightVector);
	graph.weightEdge(5, 9, G2, 15, weightVector);
	graph.weightEdge(6, 10, G2, 16, weightVector);
	graph.weightEdge(7, 11, G2, 17, weightVector);
	graph.weightEdge(8, 9, G2, 18, weightVector);
	graph.weightEdge(9, 10, G2, 19, weightVector);
	graph.weightEdge(10, 11, G2, 20, weightVector);
	graph.weightEdge(8, 12, G2, 21, weightVector);
	graph.weightEdge(9, 13, G2, 22, weightVector);
	graph.weightEdge(10, 14, G2, 23, weightVector);
	graph.weightEdge(11, 15, G2, 24, weightVector);
	graph.weightEdge(12, 13, G2, 25, weightVector);
	graph.weightEdge(13, 14, G2, 26, weightVector);
	graph.weightEdge(14, 15, G2, 27, weightVector);

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

void ofApp::createWeightGraphThree() {
	G2.clear();
	G2.assign(12, std::vector<int>());

	graph.setV(9);
	vertices.resize(graph.getV());

	weightVector.assign(graph.getV(), std::vector<int>());
	for (int i = 0; i < weightVector.size(); i++) {
		weightVector[i].assign(graph.getV(), 0);
	}

	graph.weightEdge(0, 1, G2, 4, weightVector);
	graph.weightEdge(0, 3, G2, 5, weightVector);
	graph.weightEdge(1, 2, G2, 6, weightVector);
	graph.weightEdge(1, 4, G2, 7, weightVector);
	graph.weightEdge(2, 5, G2, 8, weightVector);
	graph.weightEdge(3, 4, G2, 8, weightVector);
	graph.weightEdge(3, 6, G2, 10, weightVector);
	graph.weightEdge(4, 5, G2, 11, weightVector);
	graph.weightEdge(4, 7, G2, 12, weightVector);
	graph.weightEdge(5, 8, G2, 13, weightVector);
	graph.weightEdge(6, 7, G2, 14, weightVector);
	graph.weightEdge(7, 8, G2, 15, weightVector);

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

void ofApp::createGraph(string filename) {
	std::vector<string> linesOfTheFile;
	ofBuffer buffer = ofBufferFromFile(filename);

	for (auto line : buffer.getLines()) {
		//std::cout << line.c_str() << std::endl;
		linesOfTheFile.push_back(line);
	}

	ofFile fileToRead(ofToDataPath(filename));

	int V = atoi(linesOfTheFile[0].c_str());

	graph.setup(V);

	G2.clear();
	G2.resize(V);
	vertices.resize(graph.getV());
	verticesPos.resize(V);
	weightVector.clear();
	weightVector.assign(graph.getV(), std::vector<int>());
	for (int i = 0; i < weightVector.size(); i++) {
		weightVector[i].assign(graph.getV(), 0);
	}

	int v1, v2;
	double firstX, firstY, secondX, secondY;
	int weight;

	for (int i = 1; i < linesOfTheFile.size(); i++) {
		//std::cout << linesOfTheFile[i] << std::endl;
		v1 = atoi(linesOfTheFile[i].c_str());
		
		string number;
		number = linesOfTheFile[i][2];

		int nextDigit;

		// firstX
		for (int j = 3; j < linesOfTheFile[i].size(); j++) {
			if (linesOfTheFile[i][j] != ' ') {
				number += linesOfTheFile[i][j];
			}
			else {
				nextDigit = j + 1;
				break;
			}
		}
		firstX = stod(number);

		// firstY
		number = "";
		for (int j = nextDigit; j < linesOfTheFile[i].size(); j++) {
			if (linesOfTheFile[i][j] != ' ') {
				number += linesOfTheFile[i][j];
			}
			else {
				nextDigit = j + 1;
				break;
			}
		}
		firstY = stod(number);

		// second vertice
		v2 = int(linesOfTheFile[i][nextDigit]) - 48;
		nextDigit += 2;

		// secondX
		number = "";
		for (int j = nextDigit; j < linesOfTheFile[i].size(); j++) {
			if (linesOfTheFile[i][j] != ' ') {
				number += linesOfTheFile[i][j];
			}
			else {
				nextDigit = j + 1;
				break;
			}
		}
		secondX = stod(number);

		// secondY
		number = "";
		for (int j = nextDigit; j < linesOfTheFile[i].size(); j++) {
			if (linesOfTheFile[i][j] != ' ') {
				number += linesOfTheFile[i][j];
			}
			else {
				nextDigit = j + 1;
				break;
			}
		}
		secondY = stod(number);

		// weight
		number = "";
		for (int j = nextDigit; j < linesOfTheFile[i].size(); j++) {
			if (linesOfTheFile[i][j] != ' ') {
				number += linesOfTheFile[i][j];
			}
			else {
				nextDigit = j + 1;
				break;
			}
		}
		weight = stoi(number);

		graph.weightEdge(v1, v2, G2, weight, weightVector);

		if (verticesPos[v1].size() == 0) {
			verticesPos[v1].push_back(firstX);
			verticesPos[v1].push_back(firstY);
		}

		if (verticesPos[v2].size() == 0) {
			verticesPos[v2].push_back(secondX);
			verticesPos[v2].push_back(secondY);
		}
	}

	for (int i = 0; i < vertices.size(); i++) {
		vertices[i].setup(std::to_string(i), verticesPos[i][0], verticesPos[i][1]);
	}
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
