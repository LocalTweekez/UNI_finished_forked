#include <iostream>
#include <vector>
#include "maze.h"

Maze::Maze(int dimension){
  std::vector<Maze::node*> root;
  int i,v;
  rows = dimension * 2 +1;
  cols = dimension * 2 + 1;

  for(int i = 0; i < rows; i++){
    for(int v = 0; v < cols; v++){
      Maze:: node* node;
      if(i == 0 || i == rows-1 || v == 0 || v == cols-1)
        node = new Maze::node(v, i, false, false,false, true);
      else if((i) % 2 == 0 || (v) % 2 == 0)
        node = new Maze::node(v, i, false, false , true, false);
      else
        node = new Maze::node(v, i, false, false, false, false);
      root.push_back(node);
    }
    this->container.push_back(root);
    root.clear();
  }

}


Maze::~Maze(){
  for (size_t i = 0 ; i < this->container.size() ; i++){
    for(size_t j = 0 ; j < this->container[i].size() ; j++)
      delete container[i][j];
  }
}

void Maze::DFS(){
  setUnvisited();
  std::pair<Maze::node*, Maze::node*> startSlut = GetStartEnd();
  node* N = startSlut.first;
  N->border = false;
  N->visited = true;
  std::stack<Maze::node*> S;
  S.push(N);
  while(S.size() != 0) {
      N=S.top();
      N->visited = true;
      std::vector<node*> neighbors = getNeighbor(N);
      if(neighbors.size() != 0){
        int random = rand() % neighbors.size();
        N = neighbors[random];
        N->visited = true;
        N->wall = false;
        S.push(N);
      }
      else
        S.pop();
  }
}

void Maze::drawMaze(){
  for(size_t i = 0; i < this->container.size(); i++){
    std::vector<Maze::node*> temp_v = this->container[i];
      for (size_t j = 0; j < temp_v.size(); j++){
        if(j==0 && i==1)
          std::cout<<"SS";
        else if(j==cols-1 && i==rows-2)
            std::cout<<"EE";
        else if(temp_v[j]->border == true)
          std::cout<<"▇▇";
        else if (temp_v[j]->solved == true)
          std::cout << "**";
        else if(temp_v[j]->visited==true)
          std::cout << "  ";
        else if(temp_v[j]->wall== true)
          std::cout<<"▓▓";
        else
          std::cout << "▓▓";
      }
      std::cout << '\n';
  }
}
//hämtar en random neighbor som inte är visited
//ommarkera väggen imellan som väg
std::vector<Maze::node*> Maze::getNeighbor(Maze::node* N){
  int i ,v, z, w;
  std::vector<Maze::node*> neighbors;
  i = N->x;
  v = N->y;
  node* temp_n, *walldestroy;

    if(v == 0 && i == 1){
      neighbors.push_back(getNode(1,1));
      return neighbors;
    }
    //ner
    if (v+2 <= cols){
      if (!getNode(i,v+1)->border){
        if (!getNode(i,v+2)->visited){
          neighbors.push_back(getNode(i,v+2));
        }
      }
    }
    //höger
    if(i+2<=rows){
      if (!getNode(i+1,v)->border){
        if (!getNode(i+2,v)->visited){
          neighbors.push_back(getNode(i+2,v));
        }
      }
    }
    //upp
    if(v-2 >=0){
      if (!getNode(i,v-1)->border){
        if (!getNode(i,v-2)->visited){
          neighbors.push_back(getNode(i,v-2));
        }
      }
    }
    //vänster
    if (i-2 >= 0){
      if (!getNode(i-1,v)->border){
        if (!getNode(i-2,v)->visited){
          neighbors.push_back(getNode(i-2,v));
        }
      }
    }
    
    if (neighbors.size() == 0)
    {
      return neighbors;
    }
  
    std::vector<node*> randomNeighbor;
    temp_n = neighbors[ rand() % neighbors.size()];
    z = temp_n->x;
    w = temp_n->y;
    z = z - i;
    w = w - v;
    
    walldestroy = getNode((i+(z/2)), (v +(w/2)));
    walldestroy->visited = true;
    walldestroy->wall = false;
  
    randomNeighbor.push_back(temp_n);
    return randomNeighbor;

}




std::pair<Maze::node*, Maze::node*>Maze::GetStartEnd(){
  std::pair<node* ,node*> StartEnd;
  StartEnd.first = getNode(0,1);
  StartEnd.second = getNode(cols-1, rows-2);
  return StartEnd; 
}


Maze::node* Maze::getNode(int x, int y){
  std::vector<Maze::node*> temp_v = this->container[y];
  return temp_v[x];
}

void Maze::setUnvisited(){
  for(size_t i = 0 ; i < this->container.size() ; i++){
    std::vector<Maze::node*> temp = this->container[i];
    for(size_t j = 0; j < temp.size() ; j++){
      if(temp[j]->visited==true){
        temp[j]->visited = false;
      }
    }
  }
}

