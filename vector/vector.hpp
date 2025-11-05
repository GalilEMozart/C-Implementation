#ifndef MY_VECTOR
#define MY_VECTOR

#include <cstddef>

template <typename T>
class My_vector{

    private:
        
        size_t size;
        T* static_array;
        size_t counter=0;

    public:

        My_vector(): size(1),static_array(new T[size]){};
        My_vector(size_t size):size(size){
            static_array = new T[size];
        };
        
        ~My_vector(){
            delete [] static_array;
        }
        
        size_t getzise(){
            return  this->size;
        }

        void push_back(T element);
        T pop_back();
        T operator[](int index);

    };

#endif

