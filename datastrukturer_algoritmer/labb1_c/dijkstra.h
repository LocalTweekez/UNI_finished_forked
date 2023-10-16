// Graph (represented as an adjacency list or matrix)
// Priority queue (min heap) to store vertices based on their distances
// Set to keep track of visited vertices
// Array to store distances from the source vertex to all other vertices
// Array to store the previous vertex for each vertex (to reconstruct the shortest path)

#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "graph.h"
#include <queue>

class Dijkstra : public Graph {
protected:

    std::vector<vertex> preVID;
    std::vector<weight> weights;


    std::priority_queue<
            std::pair<weight, vertex_id>,                 // Element type being a pair to contain distance to adjacent nodes
            std::vector<std::pair<weight, vertex_id>>,    // Container to store element
            std::greater<>    // Comparator
    > pqueue;
public:
    Dijkstra(adjacency_list& _graph);
    void findShortestPath(int startVID, int destVID);
    void findShortestPath(int startVID);
    void printShortestPath(int destVID);
};









#endif