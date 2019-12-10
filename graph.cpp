#include "graph.h"


graph::graph()
{
}

void graph::setup(int V, int E) {
	_V = V;
	_E = E;
	dist = new int[_V];
	sptSet = new bool[_V];

	for (int i = 0; i < _V; i++)
		sptSet[i] = false, dist[i] = INT_MAX;
}

void graph::drawEdgeWeight(vertice a, vertice b, int weight) {
	double midX = (a.getX() + b.getX()) / 2;
	double midY = (a.getY() + b.getY()) / 2;
	ofDrawBitmapString(std::to_string(weight), midX + 10, midY + 15);
}

void graph::edge(int a, int b, std::vector<std::vector<int>> &G){
	G[a].push_back(b);
	G[b].push_back(a);
}

void graph::weightEdge(int a, int b, std::vector<std::vector<int>>& G, int weight, std::vector<std::vector<int>> &weightVector) {
	G[a].push_back(b);
	G[b].push_back(a);
	weightVector[a][b] = weight;
	weightVector[b][a] = weight;
}

void graph::BFS(int s, std::vector<std::vector<int>> G, int v, std::vector<int> &visitedToDraw) {
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}
	std::queue<int> q;

	q.push(s);
	visited[s] = true;

	
	while (!q.empty()) {
		int f = q.front();
		std::cout << f << " ";
		visitedToDraw.push_back(f);
		q.pop();

		for (auto i = G[f].begin(); i != G[f].end(); i++) {
			if (!visited[*i]) {
				visited[*i] = true;
				q.push(*i);
			}
		}
	}
}

bool graph::BFS2(std::vector<std::vector<int>> G, int s, int dest, int v, int pred[], int dist[], std::vector<int> &visitedToDraw) {
	std::list<int> queue;
	bool* visited = new bool[v];

	for (int i = 0; i < v; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
		pred[i] = -1;
	}

	visited[s] = true;
	dist[s] = 0;
	queue.push_back(s);

	while (!queue.empty()) {
		int f = queue.front();
		visitedToDraw.push_back(f);
		queue.pop_front();
		for (int i = 0; i < G[f].size(); i++) {
			if (visited[G[f][i]] == false) {
				visited[G[f][i]] = true;
				dist[G[f][i]] = dist[f] + 1;
				pred[G[f][i]] = f;
				queue.push_back(G[f][i]);

				if (G[f][i] == dest)
					return true;
			}
		}
	}
}

void graph::BFSPath(std::vector<std::vector<int>> G, int s, int dest, int v, std::vector<int> &visitedToDraw, std::vector<int> &pathToDraw) {
	int* pred = new int[v];
	int* dist = new int[v];

	BFS2(G, s, dest, v, pred, dist, visitedToDraw);

	std::vector<int> path;
	int crawl = dest;
	path.push_back(crawl);
	while (pred[crawl] != -1) {
		//std::cout << pred[crawl] << " ";
		path.push_back(pred[crawl]);
		crawl = pred[crawl];
	}

	std::cout << "Shortest path length - " << dist[dest] << std::endl;
	std::cout << "Path: ";

	for (int i = path.size() - 1; i >= 0; i--) {
		std::cout << path[i] << " ";
		pathToDraw.push_back(path[i]);
	}
}

void graph::DFSUtil(int v, bool visited[], std::vector<std::vector<int>> G, std::vector<int> &pathToDraw) {
	visited[v] = true;
	std::cout << v << " ";
	pathToDraw.push_back(v);

	for (auto i = G[v].begin(); i != G[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited, G, pathToDraw);
}

void graph::DFS(int v, std::vector<std::vector<int>> G, int V, std::vector<int> &pathToDraw) {
	bool* visited = new bool[V];

	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	DFSUtil(v, visited, G, pathToDraw);
}

int graph::minDistance(int dist[], bool sptSet[], int V) {
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) {
			min = dist[v], min_index = v;
			// set vertice weight
		}
	return min_index;
}

void graph::Dijkstra(std::vector<std::vector<int>> weightVector, int s, int dist[], bool sptSet[], std::vector<vertice> &vertices) {
	dist[s] = 0;

	// rysowaæ jak BFS

	int u = minDistance(dist, sptSet, _V);
	sptSet[u] = true;
	for (int v = 0; v < _V; v++)
		if (!sptSet[v] && weightVector[u][v] && dist[u] != INT_MAX
			&& dist[u] + weightVector[u][v] < dist[v]) {
			dist[v] = dist[u] + weightVector[u][v];
			vertices[v].setWeight(dist[v]);
		}

	for (int i = 0; i < _V; i++)
		std::cout << i << " " << dist[i] << std::endl;

}

int graph::getV() {
	return _V;
}

void graph::setV(int newV) {
	_V = newV;
}

int * graph::getDist() {
	return dist;
}

void graph::setDist(int newDist[]) {
	dist = newDist;
}

bool * graph::getSptSet() {
	return sptSet;
}

void graph::setSptSet(bool newSptSet[]) {
	sptSet = newSptSet;
}


graph::~graph()
{
}
