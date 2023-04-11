#include "linked_list.h"
#include <iostream>

void pushback(linked_list& l1);
void atRemove(linked_list& l1, linked_list& l2);
void print_list(linked_list& l);
linked_list merge(linked_list& l1, linked_list& l2);
bool sort_check(linked_list& l);

int main(){
    linked_list lista1, lista2;
    linked_list lista3;
    std::cout << "UPPGIFT 1 (PUSH_BACK)"<<std::endl;
    std::cout << "==========================================="<<std::endl;
    pushback(lista1);
    pushback(lista2);
    print_list(lista1);
    print_list(lista2);

    std::cout << "\n\nUPPGIFT 2 (At och Remove)"<<std::endl;
    std::cout << "==========================================="<<std::endl;
    atRemove(lista1, lista2);
    print_list(lista1);
    print_list(lista2);

    
    /*std::cout << "\nUPPGIFT 3 och 4 (operator = , pop_back - push_front)"<<std::endl;
    std::cout << "==========================================="<<std::endl;
    if (lista1.size() < lista2.size()){
        lista3 = lista1;
        for (int i = 0; i < 25; i++){
            lista2.push_front(lista2.pop_back());
            lista2.pop_back();
            
        }
    print_list(lista2);
    }
    else if (lista1.size() > lista2.size()){
        lista3 = lista2;
        for (int i = 0; i < 25; i++){
            lista1.push_front(lista1.pop_back());
            lista1.pop_back();
        }
        print_list(lista1);
    }
    else{
        lista3 = lista1;
        for (int i = 0; i < 25; i++){
            lista2.push_front(lista2.pop_back());
            lista2.pop_back();
            
        }
        print_list(lista2);
    }*/

    std::cout << "\n\nUPPGIFT 6 (merge)"<<std::endl;
    std::cout << "==========================================="<<std::endl;
    linked_list mergedlist = merge(lista1, lista2);
    if (sort_check(mergedlist)==true){
            std::cout << " The list is sorted "<<std::endl;
            print_list(mergedlist);
    }
    else{
        std::cout << " The list is not sorted "<<std::endl;
        print_list(mergedlist);
    }
    

    return 0;
}


void pushback(linked_list& l1){
 
    for(int i = 0; i < 50; i++){
        if(i == 0)
            l1.push_back(rand() % 5);
        else
            l1.push_back(l1.back()+ rand()%5);
    }
}
void atRemove(linked_list& l1, linked_list& l2){

    if(l1.at(24)>l2.at(24)){
        std::cout << "talet som tas bort är "<<l1.at(24)<<" från lista 1"<<std::endl;
        l1.remove(24);
    }
    else if(l1.at(24)<l2.at(24)){
        std::cout << "talet som tas bort är "<<l2.at(24)<<" från lista 2"<<std::endl;
        l2.remove(24);
    }
    else{
        std::cout << "talet som tas bort är"<<l2.at(24)<<" från lista 2"<<std::endl;
        l2.remove(24);
    }
}

void print_list(linked_list& l){
    for (int i = 0; i < l.size(); i++){
        std::cout << l.at(i) << " ";
    }
    std::cout << "\n";
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

    for(int i=0; i<l.size()-1; i++){
        if(l.at(i) > l.at(i+1)){
        std::cout << "not sorted;"<< " ";
        return false;
        }
    }
    std::cout << " sorted"<<std::endl;
    return true;
}
