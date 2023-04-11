#pragma once

#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <map>

class Maze {
private:
    struct node {

        int x, y;
        bool solved = false;
        bool wall = false;
        bool visited = false;
        bool border = false;
        node(int x, int y, bool visited, bool solved, bool wall, bool border):
        x(x), y(y), visited(visited), solved(solved), wall(wall), border(border){};

        node(const node& src){
          x = src.x;
          y = src.y;
          wall = src.wall;
          visited = src.visited;
          solved = src.solved;
          border = src.border;
        };
    };
    int rows, cols;
    std::vector<std::vector<Maze::node*> > container;
    node* getNode(int x, int y);
    void setUnvisited();
    std::pair<node*,node*> GetStartEnd();
    std::vector<Maze::node*> getNeighbor(node* N);
    

public:

    Maze(int dimension);
    ~Maze();
    void DFS();
    void drawMaze();
};
