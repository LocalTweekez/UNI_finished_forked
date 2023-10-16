#include "reader.h"

#include<fstream>
#include<string>
#include<map>
#include <Windows.h>




token get_line_type(std::istream& is) {
    switch (is.peek()) {
        case std::istream::traits_type::eof():
            return END_OF_FILE;
        case '#':
            return COMMENT;
        case 'M':
            return META;
    };
    return EDGE;
}

vertexlist vert_list;

edge read_edge(std::istream& is) {
    edge e;
    is >> e.node1 >> e.node2 >> e.weight;
    std::getline(is, e.desc);
    return e;
}

void read_vertex(std::istream& is) {
    char discard;
    vertex vert;
    is >> discard >> vert.id;
    std::getline(is, vert.desc);
    // From Windows.h
    // Set console code page to UTF-8 so console known how to interpret string data
    SetConsoleOutputCP(CP_UTF8);

    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    setvbuf(stdout, nullptr, _IOFBF, 1000);
    vert_list.push_back(vert);
}

adjacency_list parse_file(std::string filename) {
    std::ifstream in(filename);
    token l;
    edgelist edge_list;
    while ((l = get_line_type(in)) != END_OF_FILE) {
        edge e;
        switch (l) {
            case token::EDGE:
                e = read_edge(in);
                edge_list.push_back(e);
                break;
            case token::META:
                read_vertex(in);
                break;
            default:
                std::string comment;
                std::getline(in, comment);
        }
    }
    return adjacency_list{ vert_list, edge_list };

}