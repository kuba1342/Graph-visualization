#include "ofApp.h"
#include <iostream>
#include <vector>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	vertice.setup("1", 500, 500);

	// Reading file
	vector < string > linesOfTheFile;
	ofBuffer buffer = ofBufferFromFile("tinyG.txt");
	for (auto line : buffer.getLines()) {
		std::cout << line.c_str() << std::endl;
		linesOfTheFile.push_back(line);
	}

	if (linesOfTheFile.size() != 0)
		std::cout << linesOfTheFile[0];
	else
		std::cout << "empty";
	ofFile fileToRead(ofToDataPath("tinyG.txt"));
	if (doesFile)
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
