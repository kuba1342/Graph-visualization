#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include "vertice.h"
#include "ofUtils.h"


#pragma once
class graph {
	int _V;
	int _E;

	int* dist;
	int* parent;
	bool* sptSet;

	float nextEventSeconds = 0;

public:	
	std::vector<bool> visited;
	std::vector<int> dijkstraPath;

	graph();

	void setup(int V);

	void setup(int V, int E);

	void drawEdgeWeight(vertice a, vertice b, int weight);

	void edge(int a, int b, std::vector<std::vector<int>> &G);

	void weightEdge(int a, int b, std::vector<std::vector<int>> &G, int weight, std::vector<std::vector<int>> &weightVector);

	void BFS(int s, std::vector<std::vector<int>> G, int v, std::vector<int> &visitedToDraw);

	bool BFS2(std::vector<std::vector<int>> G, int s, int dest, int v, int pred[], int dist[], std::vector<int> &visitedToDraw);

	void BFSPath(std::vector<std::vector<int>> G, int s, int dest, int v, std::vector<int> &visitedToDraw, std::vector<int> &pathToDraw);

	void DFSUtil(int v, bool visited[], std::vector<std::vector<int>> G, std::vector<int> &pathToDraw);

	void DFS(int v, std::vector<std::vector<int>> G, int V, std::vector<int> &pathToDraw);

	int minDistance(int dist[], bool sptSet[], int V);

	void Dijkstra(std::vector<std::vector<int>> weightVector, int s, int dist[], bool sptSet[], std::vector<vertice> &vertices, int &current);

	void prepareDijkstra();

	void printDijkstraPath(int parent[], int j);

	int getV();

	void setV(int newV);

	int* getDist();

	void setDist(int newDist[]);

	int* getParent();

	void setParent(int newParent[]);

	bool* getSptSet();

	void setSptSet(bool newSptSet[]);

	~graph();
};

