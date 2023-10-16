#include "p_queue.h"
#include <iostream>
#include <algorithm>

template<class T, class COMP>
p_queue<T, COMP>::p_queue() {

}
template<class T, class COMP>
p_queue<T, COMP>::~p_queue() {
}
template<class T, class COMP>
T p_queue<T,COMP >::pop() {
    T tmp = *data.begin();
    data.erase(data.begin());
    return tmp;
}
template<class T, class COMP>
auto p_queue<T, COMP>::begin() {
    return data.begin();
}

template<class T, class COMP>
void p_queue<T, COMP>::push(T e) {
    data.push_back(e);
    std::sort(data.begin(), data.end(),comp);

}

template<class T, class COMP>
int p_queue<T,COMP>::size()
{
    return data.size();
}

template<class T, class COMP>
bool p_queue<T,COMP>::empty()
{
    return data.empty();
}

template<class T, class COMP>
void p_queue<T,COMP>::print() {
    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i].name << "  " << data[i].price << std::endl;

    }
}
