#include "linked_list.h"
#include <iostream>

linked_list::node::node(double value) {
    node* next = nullptr;
    node* prev = nullptr;
}

linked_list::linked_list (){
    head = nullptr;
    tail = nullptr;
}

/**
 * @brief Construct a new linked list::linked list object
 * 
 * @param src 
 */

linked_list::linked_list ( const linked_list & src ){


        while(!(*this).is_empty())
            (*this).pop_front();

        if(!src.is_empty()){
            node* temp = new node(double (src.head->next->value));
            temp = src.head;
            while (src.size() != (*this).size()){
                (*this).push_back(temp->value);
                temp = temp->next;
            }

        }
    }
    


/**
 * @brief Destroy the linked list::linked list object
 * 
 */

linked_list::~linked_list(){
    node* temp= head;

    for(node* temp2 = temp; temp!=nullptr ; temp=temp2){

        temp2 = temp->next;
        delete temp;
    }

    head=nullptr;
    tail=nullptr;
}

linked_list &linked_list::operator =( const linked_list & rhs ){
    //
    if (this != &rhs){

        while(!(*this).is_empty())
            (*this).pop_front();

        if(!rhs.is_empty()){
            node* temp = new node(double (rhs.head->next->value));
            temp = rhs.head;
            while (rhs.size() != (*this).size()){
                (*this).push_back(temp->value);
                temp = temp->next;
            }

        }
    }
    return *this;
    
}

 // appends elements from rhs
linked_list& linked_list::operator +=( const linked_list & rhs ){
    node* obj1 = (*this).head;
    node* obj2 = rhs.head;

    if(!(*this).is_empty()) {
        while(obj1->next != nullptr) {
          obj1 = obj1->next;
        }
    }

    for(int i = 0; i < rhs.size(); ++i) {
        (*this).push_back(obj2->value);
        obj2 = obj2->next;
    }
    return *this;

}

 // inserting elements
void linked_list::insert ( double value , size_t pos ){
    node* newnode = new node(double(value));
    node* temp = head;
    newnode->next = nullptr;
    newnode->prev = nullptr;
    newnode->value = value;

     if(pos < 0 || pos > size()) {
        std::cerr << "Position not in range!" << std::endl;
    }
    else if (pos == 0){
        push_front(value);
    }
    else if(pos!= 0){
        for(int i = 0; i<pos; i++){
            temp = temp->next;
        }
        if(temp->next == nullptr)
            push_back(value);

        else{
            newnode->prev = temp->prev;
            newnode->next = temp;
            temp->prev = newnode;

        }
    }
}

void linked_list::push_front ( double value ){
    node* newnode = new node(double(value));
    newnode->next = nullptr;
    newnode->prev = nullptr;
    newnode->value = value;

    if (head==nullptr)
        head = newnode;
    else{
        newnode->next= head;
        head->prev = newnode;
        head= newnode;
    }
}



void linked_list::push_back ( double value ){
    node* newnode = new node(double (value));
    newnode->value = value;
    newnode->next = nullptr;

    if(head == nullptr){
    head = newnode;
    tail = newnode;
    }

    else{
        node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        tail = newnode;
    }
}

 // accessing elements
double linked_list::front () const {
    //std::cout << "at the front we have " << head->value << std::endl;
      return head->value;

    return 0;
}
double linked_list::back () const {

      //std::cout << "at the back we have " << tail->value << std::endl;
      return tail->value;

    
return 0;
}
double linked_list::at ( size_t pos ) const {

     if(pos < 0 || pos > size()) {
        std::cerr << "Position not in range!" << std::endl;
        return 0;
    }
    node* temp = head;
      for(int i = 0; i < pos; i++) {
          temp = temp->next;
        }
      //std::cout << "at " << pos << " we have: " << temp->value << std::endl;
      return temp->value;

}

 // removing elements
void linked_list::remove ( size_t pos ) {

    
    if(pos < 0 || pos > size()) {
        std::cerr << "Position not in range!" << std::endl;
    }
    else{
        node* temp = head;
        for(int i = 0; i<pos;i++){
            if(temp->next!=nullptr)
            temp = temp->next;
        }
        temp->next->prev= temp->prev;
        temp->prev->next = temp->next;
        delete temp;
    }
}

double linked_list::pop_front () {
    if (size()==0)
        //std::cout << "list is empty"<<std::endl;
        std::cout << std::endl;

    else if(size()==1){
        delete head;
        head=tail=nullptr;
    }

    else{
        
        node* newhead = head->next; 
        delete head;
        head = newhead;
        head->prev=nullptr;
        return head->value;
        
    }

    return 0;
}
double linked_list:: pop_back (){

    if (size()==0)
        std:: cout << "";
    //std::cout << "list is empty"<<std::endl;

    else if(size()==1){
        delete head;
        head=tail=nullptr;
    }

    else{
        
        node* newtail = tail->prev;
        delete tail;
        tail = newtail;
        tail->next=nullptr;

        
        return tail->value;
    }
    return 0;
}

// status
size_t linked_list:: size () const {
    
    size_t size = 1;
    if(linked_list::is_empty() == true)
        return 0;
    else{
       for(node* temp = head; temp->next != nullptr;size++) 
            temp = temp->next;

        }
    //std::cout << "size of linked list is " << size << std::endl;
    
    return size;
}
bool linked_list::is_empty () const {

    if(head==nullptr)
        return true;
    else
        return false;
    
}

 // output
void linked_list::print () const{
    
    for(node* temp=head; temp!=nullptr; temp=temp->next){
            std::cout << temp->value << std::endl;
        }
    
}
void linked_list::reverse_print () const {
    for(node* temp = tail; temp!=nullptr; temp=temp->prev){
            std::cout << temp->value << std::endl;
        }
}

