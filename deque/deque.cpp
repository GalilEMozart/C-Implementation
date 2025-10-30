#include "deque.hpp"
#include <stdexcept>
#include <iostream>

#include <stdio.h>

int Deque::back(){

    if(this->last==nullptr)
        throw std::invalid_argument("empty deque");

    return this->last->val;
};

int Deque::front(){
    if(this->first==nullptr)
        throw std::invalid_argument("empty deque");
    
        return this->first->val;
};

int Deque::pop_front(){

    if(this->first==nullptr)
        throw std::invalid_argument("empty deque");


    Node* old_node = this->first;
    int first_old_val = this->first->val;
    
    this->first = this->first->next;

    if(this->first!=nullptr)
        this->first->prev=nullptr;
    else
        this->last=nullptr;
    
    delete old_node;

    return first_old_val;
};

int Deque::pop_back(){

    if(this->last==nullptr)
        throw std::invalid_argument("empty deque");

    Node* old_last_node = this->last;
    int old_val = this->last->val;

    this->last = this->last->prev;

    if(this->last!=nullptr)
        this->last->next=nullptr;
    else
        this->first=nullptr;
    
    delete old_last_node;

    return old_val;

};

void Deque::push_back(int val){

    Node* new_node = new Node(val);

    if(this->last==nullptr || this->first==nullptr){
        this->last = new_node;
        this->first = new_node;
    }
    else{
        
        new_node->prev = this->last;
        this->last->next = new_node;
        this->last = new_node;
        
    }

};

void Deque::push_front(int val){

    Node* new_node = new Node(val);

    if(this->last==nullptr || this->first==nullptr){
        this->last = new_node;
        this->first = new_node;
    }
    else{
        
        new_node->next = this->first;
        this->first->prev = new_node;
        this->first = new_node;
    }

};

bool Deque::is_empty(){

    return this->last==nullptr && this->first==nullptr;
}
