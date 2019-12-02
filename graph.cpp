#include "graph.h"


graph::graph()
{
}

void graph::setup(int V, int E) {
	_V = V;
	_E = E;
}

void graph::edge(int a, int b, std::vector<std::vector<int>> &G){
	G[a].push_back(b);
	G[b].push_back(a);
}

void graph::BFS(int s, std::vector<std::vector<int>> G, std::vector<int> visitedToDraw) {
	std::queue<int> q;

	q.push(s);
	visited[s] = true;

	
	while (!q.empty()) {
		int f = q.front();
		std::cout << f << " ";
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
		//std::cout << f << " ";
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

int graph::getV() {
	return _V;
}

void graph::setV(int newV) {
	_V = newV;
}


graph::~graph()
{
}
