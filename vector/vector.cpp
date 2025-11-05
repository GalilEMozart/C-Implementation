#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "vector.hpp"

template<typename T>
void My_vector<T>::push_back(T element){
    
    if(this->counter < this->size){
    
        this->static_array[this->counter] = element;
        this->counter++;
    }

    else{

        T* new_static_array = new T[this->size*2];
        
        int i;
        for(i=0;i<this->size;i++){
             new_static_array[i] = this->static_array[i];
        }

        new_static_array[this->counter] = element;
        
        this->counter++;
        this->size = this->size*2;


        delete [] this->static_array;
        this->static_array = new_static_array;

    }

};

template <typename T>
T My_vector<T>::pop_back(){

    if(!this->size){
        throw std::invalid_argument("The vector is empty.");
    }
    
    this->size--;
    return this->static_array[this->counter--];

};

template <typename T>
T My_vector<T>::operator[](int index){
    
    if(!this->size){
        throw std::invalid_argument("The vector is empty.");
    }
    else if(this->size <= index){
        throw std::invalid_argument("The index is out of range the vector size.");
    }
    return this->static_array[index];
};

template class My_vector<int>;


