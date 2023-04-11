#include<iostream>
#include"maze.h"

int main() {

  int i,x;
 
  do{
    std::cout << "1.Skapa en maze;\n2.Avsluta programmet; "<<std::endl;
    std::cin>>i;
    if(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout << "fel inmatning testa 1 eller 2"<<std::endl;
      std::cin>>i;
    }
  
    switch(i){
      
      case 1:{
        std::cout << "skriv in dimensionerna; "<<std::endl;
        std::cin >>x;
        Maze maze(x);
        maze.DFS();
        maze.drawMaze();
        break;
      }
        
      case 2:{
        break;
      }
      default:{
        std::cin.ignore();
        std::cin.clear();
        break;
      }
    }
  }while(i!=2);

  return 0;
}
