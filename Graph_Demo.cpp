//compile with c++11 features 


#include "Graph.h"
 
void Graph::printGraphMatrix() {	//print n x n matrix onto standard output
	for (auto& i : adjacencyMatrix) {
		for (auto& j : i)
			std::cout << j << ' ';
		std::cout << '\n';
	}

}

void d_Graph::printGraphMatrix() {
	for (auto& i : adjacencyMatrix) {
		for (auto& j : i)
			std::cout << j << ' ';
		std::cout << '\n';
	}

}


int main(void) {
	Graph graph1{ 5 }; // a 5 vertex graph, undirected
	d_Graph graph2{ 5 };// directed 

	graph1.addEdge(0, 3); //edge connects vertices 0 and 3
	graph1.addEdge(1, 3);
	graph1.addEdge(1, 4);
	graph1.addEdge(3, 4);
	graph1.addEdge(2, 4);
	//graph1.addEdge(-1, -2); //vector subscript out of range

	std::cout << "undirected Graph:\n";
	graph1.printGraphMatrix();

	graph2.addEdge(0, 3); //edge connects vertices 0 and 3
	graph2.addEdge(1, 3);
	graph2.addEdge(1, 4);
	graph2.addEdge(3, 4);
	graph2.addEdge(4, 2);

	std::cout << "directed Graph:\n";
	graph2.printGraphMatrix();


	std::cout << "undirected graph bfs:\n";
	graph1.breadthFirstTraverse(0);
	std::cout << "directed graph bfs:" << std::endl;
	graph2.breadthFirstTraverse(0);



	return 0;
}
