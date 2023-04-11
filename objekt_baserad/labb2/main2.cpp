#include "linked_list.h"
#include <iostream>

void pushback(linked_list& l1);
void atRemove(linked_list& l1, linked_list& l2);
void print_list(linked_list& l);
linked_list merge(linked_list& l1, linked_list& l2);
bool sort_check(linked_list& l);

int main(){

    linked_list lista1, lista2;
    pushback(lista1);
    pushback(lista2);
    linked_list sorted_list = merge(lista1, lista2);
    print_list(sorted_list);
    sort_check(sorted_list);
    linked_list lista3;
    if (lista1.size() < lista2.size()){
        lista3 = lista1;
        for (int i = 0; i < 25; i++){
            lista2.pop_back();
            lista2.push_front(lista2.pop_back());
            
        }
     std::cout << "ta bort minsta";  
    print_list(lista2);
    
    }
    
    else if (lista1.size() > lista2.size()){
        lista3 = lista2;
        for (int i = 0; i < 25; i++){
            lista1.pop_back();
            lista1.push_front(lista1.pop_back());
        }
        //print_list(lista1);
    }
    else{
        lista3 = lista1;
        for (int i = 0; i < 25; i++){
            lista2.pop_back();
            lista2.push_front(lista2.pop_back());
            
    }
            //print_list(lista2);



    }

    

    
    

    
    return 0;
}


void pushback(linked_list& l1){

    for(int i = 0; i < 49; i++){
        if(i == 0)
            l1.push_back(rand() % 5);
        else
            l1.push_back(l1.back()+ rand()%5);
    }
}
void atRemove(linked_list& l1, linked_list& l2){

    if(l1.at(24)>l2.at(24))
        l1.remove(24);
    else if(l1.at(24)<l2.at(24))
        l2.remove(24);
    else
        l2.remove(24);
}

void print_list(linked_list& l){
    for (int i = 0; i < l.size(); i++){
        std::cout << l.at(i) << " ";
    }
}    

linked_list merge(linked_list& l1, linked_list& l2){
    
    linked_list sorted_list;
    while(l1.size() !=0 && l2.size() !=0){ 
        if (l1.front()<l2.front()){
            sorted_list.push_back(l1.front());
            l1.pop_front();
        }
        else if (l1.front()==l2.front()){
            sorted_list.push_back(l1.front());
            l1.pop_front();
        }
        else {
            sorted_list.push_back(l2.front());
            l2.pop_front();
        }
        
    }
     while(l2.is_empty()&& !l1.is_empty()){
         sorted_list.push_back(l1.front());
            l1.pop_front();

     }
     while(l1.is_empty()&& !l2.is_empty()){
         sorted_list.push_back(l2.front());
        l2.pop_front();

     }
    return sorted_list;
}

bool sort_check(linked_list& l){
    double a, b;

    for(int i=0; i<l.size(); i++){
        if(l.at(i) > l.at(i+1))
        std::cout << "not sorted;"<< " ";
        return false;
    }
    std::cout << " sorted"<<std::endl;
    return true;
}
