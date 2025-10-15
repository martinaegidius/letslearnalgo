#ifndef STACK_H
#define STACK_H
#include "lists/singly_linked_list.h"

class Stack : public SinglyLinkedList { 
public: 
    Stack(); //default constructor   
    void push(int key);
    int pop();
    ~Stack(); 
};

#endif