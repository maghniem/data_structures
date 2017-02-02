//#pragma once
#include <vector> //for 2d array matrix
#include <queue> 
#include <iostream>

template <typename T>
using AdjacencyMatrix = std::vector<std::vector<T>>;  //template for n x n matrix

class Graph { //undirected graph

private:
	int vertextCount;	
	AdjacencyMatrix<bool> adjacencyMatrix;
public:
	void printGraphMatrix();  

	Graph(int vertCount) : vertextCount{ vertCount }
	{
		adjacencyMatrix.resize(vertCount); //set the rows
		for (auto& index : adjacencyMatrix)
			index.resize(vertCount); // set the cols
	}

	void addEdge(int i, int j) {
		if (i != j) {
			adjacencyMatrix[i][j] = true;
			adjacencyMatrix[j][i] = true;
		}
		else
			std::cout << "vertex cannot be directed to itself, edge not added\n";
	}

	void removeEdge(int i, int j) {
			adjacencyMatrix[i][j] = false;
			adjacencyMatrix[j][i] = false;
		
	}

	bool isEdge(int i, int j) {
		if (i >= 0 && j > 0) {
			return adjacencyMatrix[i][j];
		}

		return false;
	}

	void breadthFirstTraverse(int start) {
		std::vector<int> parent;
		parent.resize(vertextCount);

		std::vector<bool> vertexVisted;
		vertexVisted.resize(vertextCount);
		for (auto& i : vertexVisted)
			i = false;

		std::priority_queue<int> q;
		q.push(start); int currentNode;
		while (!q.empty()) {
			currentNode = q.top();
			q.pop();
			std::cout << "at Node: " << currentNode  << '\n';
			for (int i = 0; i < vertextCount; i++) {				
				if (this->isEdge(currentNode, i) && !vertexVisted[i] && i != parent[currentNode])  {
					std::cout << "visited: " << i << '\n';
					vertexVisted[i] = true;
					parent[i] = currentNode;
					q.push(i);
				}
			}
		}
	}
};

class d_Graph { //directed graph

private:
	int vertextCount;
	AdjacencyMatrix<bool> adjacencyMatrix;
public:
	void printGraphMatrix();
	d_Graph(int vertCount) : vertextCount{ vertCount }
	{
		adjacencyMatrix.resize(vertCount); //set the rows
		for (auto& index : adjacencyMatrix)
			index.resize(vertCount); // set the cols
	}

	void addEdge(int i, int j) {
		if (i != j) {
			adjacencyMatrix[i][j] = true;
			//adjacencyMatrix[j][i] = true;
		}
		else
			std::cout << "vertex cannot be directed to itself, edge not added\n";
	}

	void removeEdge(int i, int j) {
		adjacencyMatrix[i][j] = false;
		//adjacencyMatrix[j][i] = false;

	}

	bool isEdge(int i, int j) {
		if (i >= 0 && j > 0) {
			return adjacencyMatrix[i][j];
		}

		return false;
	}

	void breadthFirstTraverse(int start) {
		std::vector<int> parent;
		parent.resize(vertextCount);

		std::vector<bool> vertexVisted;
		vertexVisted.resize(vertextCount);
		for (auto& i : vertexVisted)
			i = false;

		std::priority_queue<int> q;
		q.push(start); int currentNode;
		while (!q.empty()) {
			currentNode = q.top();
			q.pop();
			std::cout << "at Node: " << currentNode << '\n';
			for (int i = 0; i < vertextCount; i++) {
				if (this->isEdge(currentNode, i) && !vertexVisted[i] && i != parent[currentNode]) {
					std::cout << "visited: " << i << '\n';
					vertexVisted[i] = true;
					parent[i] = currentNode;
					q.push(i);
				}
			}
		}
	}
};