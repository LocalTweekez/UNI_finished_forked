#include "dijkstra.h"
#include <limits>
#include <vector>
#include<list>
Dijkstra::Dijkstra(adjacency_list& _graph) : Graph(_graph) {
    preVID.resize(totalVerticies);
    weights.resize(totalVerticies);

}






/*void dijkstra::findShortestPath(int startVID, int destVID) {
    for(int i = 0; i < totalVerticies; i++){
        weights[i] = std::numeric_limits<double>::infinity();
        this->visited[i] = notVisited;
        preVID[i].id = NULL;
        if (i != destVID){
            pqueue.push(std::make_pair(i, startVID));
        }
    }

}*/

void Dijkstra::findShortestPath(vertex_id startVID) {
    // Begin with initializing the graph as entirely unvisited with
    // infinite amount of distance between each vertex
    for(int i = 0; i < totalVerticies; i++){
        weights[i] = std::numeric_limits<double>::infinity();
        this->visited[i] = notVisited;
        preVID[i].id = NULL;
    }

    // Starting vertex distance from starting point is zero
    weights[startVID] = 0;
    pqueue.push(std::make_pair(0, startVID));

    while (!pqueue.empty()) {
        int currentVID = pqueue.top().second;
        pqueue.pop();
        std::cout<< currentVID << std::endl;

        if (visited[currentVID]) {
            continue;
        }
        visited[currentVID] = visited;
        for (auto& e : graph.second) {
            // Target the current vertex and calculate distance from this to the next
            if (e.node1 == currentVID) {
                int vDestID = e.node2;
                double weight = e.weight;

                // Add weight value for each unvisited node from vID to vDestID
                if (weights[vDestID] > weights[currentVID] + weight) {
                    weights[vDestID] = weights[currentVID] + weight;
                    preVID[vDestID].id = currentVID;
                    pqueue.push(std::make_pair(weights[vDestID], vDestID));
                }
            }
        }
    }
}

void Dijkstra::printShortestPath(vertex_id destVID) {
    std::cout << "shortest path:" << std::endl;

    // Lambda function to return and store description of each assigned vertexID
    auto location = [this](int i) {
        for (auto it = this->graph.first.begin(); it != this->graph.first.end(); ++it) {
            if (i == it->id) {
                return it->desc;
            }
        }
        desc desc = "no desc found";
        return desc;
    };

    std::list<vertex_id> path;

    // Reverse from the destination vertex back to starting point
    //
    int current = destVID;
    while (current != NULL) {
        path.push_front(current);
        current = preVID[current].id;
    }

    for (auto& v : path) {
        std::cout << location(v) << ", ";
    }
    std::cout << "distance: " << weights[destVID];

}
