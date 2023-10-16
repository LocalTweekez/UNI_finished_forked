#include "graph.h"



Graph::Graph(adjacency_list& _graph) :
        graph(_graph),
        totalVerticies(_graph.first.size()),
        visited(new bool[totalVerticies]) {
    for(int i = 0; i < totalVerticies; i++){
        visited[i] = notVisited;
    }

}

vertex Graph::getVertex(vertex_id vID) {
    for(int i = 0; i < graph.first.size(); i++){
        if (graph.first[i].id == vID) {
            return graph.first[i];
        }
    }
    std::cout << "vertex with ID" << vID << " couldn't be found" << std::endl;
    return { -1, "-1" };
}

vertexlist Graph::getAdjacentVertexes(vertex_id vID) {
    vertexlist adjVertList;
    for(int i = 0; i < graph.second.size(); i++){
        if (graph.second[i].node1 == vID) {
            adjVertList.push_back(getVertex(graph.second[i].node2));
        }
        else if (graph.second[i].node2 == vID) {
            adjVertList.push_back(getVertex(graph.second[i].node1));
        }
    }
    return adjVertList;
}

void Graph::DFS(vertex_id vID) {
    visited[vID] = isVisited;
    vertexlist adjList = getAdjacentVertexes(vID);

    std::cout << vID << ", ";


    for (auto it = adjList.begin(); it != adjList.end(); ++it) {
        if (visited[it->id] == notVisited) {
            DFS(it->id);
        }
    }
}

void Graph::BFS(vertex_id startingVertexId) {
    vertexlist queue;

    for(int i = 0; i < totalVerticies; i++){
        visited[i] = notVisited;
    }
    visited[startingVertexId] = isVisited;
    queue.push_back(getVertex(startingVertexId));
    while (!queue.empty()) {
        vertex_id currVert = queue.front().id;
        vertexlist adjacents = getAdjacentVertexes(currVert);
        queue.erase(queue.begin());
        std::cout << currVert << ", ";
        for(int i = 0; i < adjacents.size(); i++){
            if (visited[adjacents[i].id] == notVisited) {
                visited[adjacents[i].id] = visited;
                queue.push_back(adjacents[i]);
            }

        }

    }


}

vertex_id Graph::findVertexId(std::string vertexDesc)
{
    return vertex_id();
}

void Graph::vertexesNotReached() {

}
