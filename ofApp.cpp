#include "ofApp.h"
#include <iostream>
#include <vector>
#include <typeinfo>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	vertice.setup("1", 500, 500);

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
		std::cout << linesOfTheFile[i] << std::endl;
		v1 = atoi(linesOfTheFile[i].c_str());
		v2 = int(linesOfTheFile[i][2]) - 48;
		G[v1].push_back(v2);
	}

	for (int i = 0; i < G.size(); i++) {
		std::cout << i << " ";
		for (int j = 0; j < G[i].size(); j++) {
			std::cout << G[i][j] << " ";
		}
		std::cout << std::endl;
	}	

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	vertice.draw();
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
