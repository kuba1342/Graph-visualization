#pragma once

#include "ofMain.h"
#include "vertice.h"
#include "graph.h"
#include <time.h>

class ofApp : public ofBaseApp {

	graph graph;
	vector<vector<int>> G2;
	vector<vector<int>> weightVector;
	vector<vertice> vertices;
	vector<vertice> verticesWeight;
	vector<int> visitedToDraw;
	vector<int> pathToDraw;

	int vertice;
	int start;
	int destination;
	float nextEventSeconds = 0;
	int count = 0;
	int current;

	bool executing = false;
	bool startSelected = false;
	bool destinationSelected = false;
	bool pathMode = true;
	int mode = 1;

	ofColor red = (255, 0, 0);

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		void delay(int number_of_seconds);
		void reset();
		void changeMode();

		void clearVectors();

		void createGraphFour();
		void createGraphThree();

		void createWeightGraphFour();
		void createWeightGraphThree();
};
