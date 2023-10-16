#ifndef GRAPH_H
#define GRAPH_H
#include "reader.h"

const bool isVisited = true;
const bool notVisited = false;

class Graph {
protected:
    int totalVerticies;
    bool* visited;
    adjacency_list graph;

public:
    Graph(adjacency_list& _graph);
    ~Graph() { delete visited; }
    vertex getVertex(vertex_id vID);
    vertexlist getAdjacentVertexes(vertex_id vID);
    void DFS(vertex_id vID);
    void BFS(vertex_id startingVertexId);
    vertex_id findVertexId(std::string vertexDesc);
    void vertexesNotReached();


};




#endif 