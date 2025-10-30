#include "deque.hpp"
#include <random>
#include <iostream>

void print_deque_pop_back(Deque d){
    
    std::cout << "print deque using pop_back method\n";

    while(!d.is_empty())
        std::cout << d.pop_back()<<" "; 
    std::cout << '\n';
};


void print_deque_pop_front(Deque d){
    
    std::cout << "print deque using pop_front method\n";

    while(!d.is_empty())
        std::cout << d.pop_front()<<" "; 
    std::cout << '\n';
};

int main(){

    Deque deque;
    int N=10;

    //deque.push_front(10);
    std::cout << deque.is_empty() <<'\n';
    
    for(int i=0;i<N;i++){
        deque.push_back(i);
        deque.push_front(i);    
    };

    print_deque_pop_back(deque);
    print_deque_pop_front(deque);
    
}
