#include "Graph.h"
#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <string>
#include <climits>
#include <list>

using namespace std;

Graph::Graph() {
	for (int i = 0; i < MAX_VERTECIES; i++) {
		for (int j = 0; j < MAX_VERTECIES; j++) {
			adjacencyMatrix[i][j] = INT_MAX; 
		}
	}
	numberofvertices = 0;
}


void Graph::AddEdge(string source, string target, int weight) {
	int fromIndex = GetIndex(source);
	int toIndex = GetIndex(target);

	if (fromIndex == -1 || toIndex == -1)
		return;

	adjacencyMatrix[fromIndex][toIndex] = weight;
	//adjacencyMatrix[toIndex][fromIndex] = weight; -- Do not use because undirected (not symmetric)
	return;
}

void Graph::AddVertex(string label) {
	if (numberofvertices >= MAX_VERTECIES)
		return;

	vertices[numberofvertices++].label = label;
}

// -1 if label is not found
int Graph::GetIndex(string label) {
	for (int i = 0; i < numberofvertices; i++)
	{
		if (vertices[i].label == label)
			return i;
	}
	return -1;
}

bool Graph::IsEdge(int sourceIndex, int targetIndex) {
	if (adjacencyMatrix[sourceIndex][targetIndex] != INT_MAX) {
		return true;
	}
	else {
		return false;
	}
}

int Graph::GetWeight(int sourceIndex, int targetIndex) {
	return adjacencyMatrix[sourceIndex][targetIndex];
}

void Graph::BreadthFirstSearch(string startingVertex) {
	int visited[MAX_VERTECIES];
	BreadthFirstSearch(startingVertex, visited);
}

void Graph::BreadthFirstSearch(string startingVertex, int visited[]) {
	//mark all vertices as not visited
	for (int i = 0; i < numberofvertices; i++) {
		vertices[i].visited = false;
	}

	//get the index of startingVertex and mark as visited
	int indexStart = GetIndex(startingVertex);
	//mark all indexes in visited[] as -1
	//Should look like {1, 2, 3, 5, 4, -1, -1, -1, -1, -1} when finished
	for (int i = 0; i < MAX_VERTECIES; i++) {
		visited[i] = -1;
	}
	
	queue<int> queue;
	vertices[indexStart].visited = true;
	visited[0] = indexStart;
	//Create a queue and add starting index
	queue.push(indexStart);
	int visitedTracker = 1;

	cout << "starting BFS with vertex " << startingVertex << endl;
	cout << '\t' << " visited " << startingVertex << endl;

	while (!queue.empty()) {
		for (int i = 0; i < numberofvertices; i++) {
			if (IsEdge(queue.front(), i) && !vertices[i].visited) {
				vertices[i].visited = true;
				visited[visitedTracker++] = i;
				queue.push(i);
				cout << '\t' << " visited " << vertices[i].label << endl;
			}
		}
		queue.pop();
	}
	cout << endl;
}

void Graph::DijkstraShortestPath(string startingVertex) {
	int distance[MAX_VERTECIES];
	int prevVertex[MAX_VERTECIES];
	DijkstraShortestPath(startingVertex, distance, prevVertex);	
}

void Graph::DijkstraShortestPath(string startingVertex, int distance[], int prevVertex[]) {
	int indexStart = GetIndex(startingVertex);

	for (int i = 0; i < numberofvertices; i++) {
		distance[i] = INT_MAX;
		prevVertex[i] = INT_MAX;
	}

	unordered_set<int> allowed;
	distance[indexStart] = 0;	// distance from a vertex to itself is 0

	for (int i = 0; i < numberofvertices; i++) {
		int next = MinDistance(distance, allowed);
		if (next == -1)	// if there are no more we can visit, MinDistance will return -1
			break;

		allowed.insert(next);

		for (int v = 0; v < numberofvertices; v++) {
			if (IsEdge(next, v) && (allowed.find(v) == allowed.end())) {
				int sum = distance[next] + GetWeight(next, v);
				if (sum < distance[v]) {
					prevVertex[v] = next;
					distance[v] = sum;
				}
			}
		}
	}

	cout << "Shortest Distance starting from vertex " << startingVertex << endl;

	for (int i = 0; i < numberofvertices; i++) {
		cout << '\t' << "to: " << vertices[i].label << '\t';
		if (distance[i] == INT_MAX || distance[i] < 0) {
			cout << "no path" << endl;
			continue;
		}
		cout << distance[i] << '\t' << "Path: " << vertices[i].label;

		int prev = prevVertex[i];
		for (int v = 0; v < numberofvertices; v++) {
			if (prev == INT_MAX) {
				break;
			}
			cout << ", " << vertices[prev].label;
			prev = prevVertex[prev];
			}
		cout << endl;
	}
	cout << endl;
}

void Graph::PrintGraph() {
	cout << "numVerticies: " << numberofvertices << endl;
	for (int i = 0; i < numberofvertices; i++){
		cout << "\t" << vertices[i].label;
	}
	cout << endl;
	for (int i = 0; i < numberofvertices; i++){
		cout << vertices[i].label;
		for (int j = 0; j < numberofvertices; j++){
			cout << "\t";
			if (adjacencyMatrix[i][j] != INT_MAX && adjacencyMatrix[i][j] != 0) {
				cout << adjacencyMatrix[i][j];
			}
		}
		cout << endl;
	}
}

int Graph::MinDistance(int distance[], unordered_set<int> allowed) {
	int minDistance = INT_MAX;
	int next = -1;	// if there are no more we can visit, this will stay -1
	for (int i = 0; i < numberofvertices; i++) {
		if (allowed.find(i) == allowed.end() && distance[i] <= minDistance) {
			minDistance = distance[i];
			next = i;
		}
	}
	return next;
}
