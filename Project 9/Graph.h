
#ifndef GRAPH_H
#define GRAPH_H

#include <set>
#include <string>
#include <stack>
#include <unordered_set>

using namespace std;

struct Vertex {
	string label;
	bool visited;
};

class Graph {

public:
	Graph();
	void AddEdge(string source, string target, int weight);
	void AddVertex(string label);
	// -1 if label is not found
	bool IsEdge(int sourceIndex, int targetIndex);
	int GetWeight(int sourceIndex, int targetIndex);
	void BreadthFirstSearch(string startingVertex);
	void BreadthFirstSearch(string startingVertex, int visited[]);
	void DijkstraShortestPath(string startingVertex);
	void DijkstraShortestPath(string startingVertex, int distance[], int prevVertex[]);
	void PrintGraph();
	int MinDistance(int distance[], std::unordered_set<int> allowed);
	int GetIndex(string label);
	static const int MAX_VERTECIES = 10;
	
private:
	int numberofvertices;
	int adjacencyMatrix[MAX_VERTECIES][MAX_VERTECIES];
	Vertex vertices[MAX_VERTECIES];
};
#endif
