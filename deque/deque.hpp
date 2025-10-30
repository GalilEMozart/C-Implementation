#ifndef DEQUE
#define DEQUE

struct  Node
{
    int val;
    Node* next;
    Node * prev;

    Node(int val):val(val), next(nullptr), prev(nullptr){};
    Node()=default;
    
};


class Deque{



    public:

        Node* first;
        Node* last;

        Deque(): first(nullptr), last(nullptr){

        };

        int front();
        int back();

        int pop_front();
        int pop_back();
        
        void push_front(int);
        void push_back(int);

        void resize(int);
        bool is_empty();

};

#endif
