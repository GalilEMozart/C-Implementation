#include "vector.hpp"
#include <iostream>

int main(){

    My_vector<int> vector(5);
    
    std::cout << "Size of vector after init: "<< vector.getzise() <<'\n';

    for(int i=0;i<25;i++){
        vector.push_back(i);
    }

    std::cout << "Size of vector after push_back: "<< vector.getzise() <<'\n';
    std::cout << "Print vector content" <<'\n';

    std::cout << '\t';

    for(int i=0;i<25;i++){
        std::cout<< vector[i] << " ";
    
    }

    std::cout  <<'\n';

    for(int i=0;i<21;i++){
        vector.pop_back();
    }
    
    std::cout << "Size of vector after pop_back: "<< vector.getzise() <<'\n';

    try
    {
        vector[25];
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    

    return 0;

};
