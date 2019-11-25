#include "ofApp.h"
#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	//vertice.setup("1", 500, 500);

	// Reading file
	vector < string > linesOfTheFile;
	ofBuffer buffer = ofBufferFromFile("tinyG.txt");
	for (auto line : buffer.getLines()) {
		linesOfTheFile.push_back(line);
	}

	int V = atoi(linesOfTheFile[0].c_str());
	int E = atoi(linesOfTheFile[1].c_str());
	graph.setup(V, E);

	int v1, v2;

	G.resize(V);

	for (int i = 2; i < linesOfTheFile.size(); i++) {
		//std::cout << linesOfTheFile[i] << std::endl;
		v1 = atoi(linesOfTheFile[i].c_str());
		v2 = int(linesOfTheFile[i][2]) - 48;
		G[v1].push_back(v2);
	}

	int x = 100;
	int y = 100;
	int loopCounter = 0;

	vertices.resize(V);

	for (int i = 0; i < G.size(); i++) {
		//std::cout << i << " ";
		vertices[i].setup(std::to_string(i), x, y);
		x += 300;
		loopCounter += 1;
		if (loopCounter == 3) {
			x = 100;
			y += 300;
			loopCounter = 0;
		}
		for (int j = 0; j < G[i].size(); j++) {
			//std::cout << G[i][j] << " ";
		}
		//std::cout << std::endl;
	}	

	std::vector<int> visitedToDraw;

	G2.assign(12, std::vector<int>());

	graph.visited.assign(9, false);

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

	//graph.BFS(2, G2, visitedToDraw);

	graph.BFSPath(G2, 0, 8, 9);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//vertice.draw();
	for (int i = 0; i < vertices.size(); i++) {
		for (int j = 0; j < G[i].size(); j++) {
			ofDrawLine(vertices[i].getX(), vertices[i].getY(), vertices[G[i][j]].getX(), vertices[G[i][j]].getY());
		}
		vertices[i].draw();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
