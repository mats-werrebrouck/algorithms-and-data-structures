#include "graph.h"

using namespace std;

Graph::Graph(int numVertices) {
    this->numVertices = numVertices;
    this->adjList.resize(numVertices);
}

Graph::~Graph() {}

void Graph::addEdge(int src, int dest) {
    this->adjList[src].push_back(dest);
    this->adjList[dest].push_back(src);
}

void Graph::removeEdge(int src, int dest) {
    // Iterate through the adjacency list of the source vertex
    for (int i = 0; i < this->adjList[src].size(); i++) {
        // If the destination vertex is found, remove it
        if (this->adjList[src][i] == dest) {
            // Remove the destination vertex from the adjacency list
            // by erasing the element at index i (i.e. the destination vertex)
            this->adjList[src].erase(this->adjList[src].begin() + i);
            break;
        }
    }

    // Iterate through the adjacency list of the destination vertex
    for (int i = 0; i < this->adjList[dest].size(); i++) {
        // If the source vertex is found, remove it
        if (this->adjList[dest][i] == src) {
            // Remove the source vertex from the adjacency list
            // by erasing the element at index i (i.e. the source vertex)
            this->adjList[dest].erase(this->adjList[dest].begin() + i);
            break;
        }
    }
}

void Graph::printGraph() {
    for (int i = 0; i < this->numVertices; i++) {
        cout << "Vertex " << i << " is connected to: ";
        for (int j = 0; j < this->adjList[i].size(); j++) {
            cout << this->adjList[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.printGraph();

    g.removeEdge(2, 3);
    g.printGraph();

    return 0;
}