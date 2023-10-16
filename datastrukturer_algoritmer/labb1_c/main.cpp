#include <iostream>
#include "reader.h"
#include "graph.h"
#include "dijkstra.h"




void print_list(adjacency_list list) {

    for(int i = 0; i < list.first.size(); i++){
        std::cout << list.first[i].id << "--------" << list.first[i].desc << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    for(int i = 0; i < list.second.size(); i++){
        std::cout << list.second[i].node1 << std::endl;
    }
}

int main() {
    adjacency_list list = parse_file("C:/Users/tahak/source/repos/UNI/datastrukturer_algoritmer/labb1_c/edges");
//    print_list(list);
//    Graph graph(list);
//    graph.DFS(3);
//    //std::cout << std::endl;
//    graph.BFS(3);
    Dijkstra diJk(list);

    diJk.findShortestPath(46);
    diJk.printShortestPath(47);

    return 0;
}
