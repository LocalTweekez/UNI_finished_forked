#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string>


class linked_list {
public:

    linked_list () ;
    linked_list ( const linked_list & src ) ;

    ~linked_list () ;

    linked_list& operator=( const linked_list& rhs ) ;

    // appends elements from rhs
    linked_list& operator+=( const linked_list& rhs ) ;

    // inserting elements
    void insert ( double value , std::size_t pos ) ;
    void push_front ( double value ) ;
    void push_back ( double value ) ;

    // accessing elements
    double front () const ;
    double back () const ;
    double at ( std::size_t pos ) const ;

    // removing elements
    void remove ( std::size_t pos ) ;
    double pop_front () ;
    double pop_back () ;

    // status
    std::size_t size () const ;
    bool is_empty () const ;

    // output
    void print () const ;
    void reverse_print () const ;

private:
    struct node {
        node(double value) ; // konstruktor f  ̈o r noden
        double value ;
        node* next ;
        node* prev ;
    };
    node* head ;
    node* tail ;
};

#endif