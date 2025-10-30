#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "vector.hpp"


void My_vector::push_back(int element){
    
    if(this->counter < this->size){
    
        this->static_array[this->counter] = element;
        this->counter++;
    }

    else{

        int* new_static_array = new int[this->size*2];
        
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

int My_vector::pop_back(){

    if(!this->size){
        throw std::invalid_argument("The vector is empty.");
    }
    
    this->size--;
    return this->static_array[this->counter--];

};

int My_vector::operator[](int index){
    
    if(!this->size){
        throw std::invalid_argument("The vector is empty.");
    }
    else if(this->size <= index){
        throw std::invalid_argument("The index is out of range the vector size.");
    }
    return this->static_array[index];
}


