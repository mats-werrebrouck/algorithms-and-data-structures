#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

class Graph {
    private:
        int numVertices;
        std::vector<std::vector<int>> adjList;

    public:
        Graph(int numVertices);
        ~Graph();

        void addEdge(int src, int dest);
        void removeEdge(int src, int dest);

        void printGraph();
};

#endif