#include "vector.hpp"
#include <chrono>
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

template < typename T>
long long benchmark(T func){

    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()/1000.0;
}

int main(int argc, char const *argv[])
{
    int N = 1'000'0000;
    
    My_vector custom_vector;
    std::vector<int> stl_vector;

    //push
    auto result_custom_vector_push = benchmark([&](){
        
        for(int i=0;i<N;i++)
            custom_vector.push_back(i);
    });

    auto resutl_stl_vector_push = benchmark([&](){
        
        for(int i=0;i<N;i++)
            stl_vector.push_back(i);
    });

    
    // random acces [] opertor  
    auto result_custom_vector_op = benchmark([&](){
        
        for(int i=0;i<N;i++){

            int id = rand()%N;
            custom_vector[id];
        }
    });

    auto resutl_stl_vector_op = benchmark([&](){
        
        for(int i=0;i<N;i++){

            int id = rand()%N;
            stl_vector.push_back(i);
        }

    });

    //pop
    auto result_custom_vector_pop = benchmark([&](){
        
        for(int i=0;i<N;i++)
            custom_vector.pop_back();
    });

    auto resutl_stl_vector_pop = benchmark([&](){
        
        for(int i=0;i<N;i++)
            stl_vector.pop_back();
    });

    
    //printing result

    std::string sep(53,'-');
    std::cout << std::setw(15) << " "
            << "| Costum vector "
            << std::setw(20) 
            << "| STL implementation"
            << " |\n";
    
    std::cout << sep << '\n';

    
    std::cout << std::setw(15) << "push_back"
            << "| " << std::setw(14) << std::fixed << std::setprecision(2) << result_custom_vector_push << " ms"
            << "| " << std::setw(12) << std::fixed << std::setprecision(2) << resutl_stl_vector_push << " ms |\n";
    
    std::cout << sep <<"\n";


    std::cout << std::setw(15) << "pop_back"
        << "| " << std::setw(14) << std::fixed << std::setprecision(2) << result_custom_vector_pop << " ms"
        << "| " << std::setw(12) << std::fixed << std::setprecision(2) << resutl_stl_vector_pop << " ms |\n";

    
    std::cout << sep <<"\n";
    
    std::cout << std::setw(15) << "[] operator"
        << "| " << std::setw(14) << std::fixed << std::setprecision(2) << result_custom_vector_op << " ms"
        << "| " << std::setw(12) << std::fixed << std::setprecision(2) << resutl_stl_vector_op << " ms |\n";

    std::cout << sep <<"\n";

    return 0;
}
