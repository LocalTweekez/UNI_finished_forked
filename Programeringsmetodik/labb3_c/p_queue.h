#ifndef P_QUEUE_H
#define P_QUEUE_H

#include <vector>

template<class T, class COMP = std::less<>>
class p_queue {

private:
    std::vector<T> data;
    COMP comp;

public:

    p_queue();
    ~p_queue();
    T pop();
    auto begin();
    void push(T e);
    int size();
    bool empty();
    void print();

};

#endif