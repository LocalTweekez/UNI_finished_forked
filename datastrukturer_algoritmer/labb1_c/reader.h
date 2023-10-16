#ifndef READER_H
#define READER_H

#include<istream>
#include<iostream>
#include<map>
#include<vector>



using vertex_id = int;
using desc = std::string;
using weight = double;
//using vertexlist = std::map<vertex_id, desc>;

enum token {
    COMMENT,
    META,
    EDGE,
    END_OF_FILE
};

struct edge {
    vertex_id node1, node2;
    weight weight;
    desc desc;
};
struct vertex {
    vertex_id id;
    desc desc;
};

typedef std::vector<vertex> vertexlist;
typedef std::vector<edge> edgelist;
typedef std::pair<vertexlist, edgelist> adjacency_list;

adjacency_list parse_file(std::string filename);

#endif //READER_H 