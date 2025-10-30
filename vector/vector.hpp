#ifndef MY_VECTOR
#define MY_VECTOR

//#include <cstddef>

class My_vector{

    private:
        
        size_t size;
        int* static_array;
        size_t counter=0;

    public:

        My_vector(): size(1),static_array(new int[size]){};
        My_vector(size_t size):size(size){
            static_array = new int[size];
        };
        
        ~My_vector(){
            delete [] static_array;
        }
        
        size_t getzise(){
            return  this->size;
        }

        void push_back(int element);
        int pop_back();
        int operator[](int index);

    };

#endif
