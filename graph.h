#include <iostream>
#include <vector>
#include <list>
#include <queue>


#pragma once
class graph {
	int _V;
	int _E;


public:	
	std::vector<bool> visited;

	graph();

	void setup(int V, int E);

	void edge(int a, int b, std::vector<std::vector<int>> &G);

	void BFS(int s, std::vector<std::vector<int>> G, std::vector<int> visitedToDraw);

	bool BFS2(std::vector<std::vector<int>> G, int s, int dest, int v, int pred[], int dist[], std::vector<int> &visitedToDraw);

	void BFSPath(std::vector<std::vector<int>> G, int s, int dest, int v, std::vector<int> &visitedToDraw, std::vector<int> &pathToDraw);

	~graph();
};

