#include "lists/stack.h"
#include <iostream>
#include <stdexcept>

//a queue implementation using singly linked list. As such, overflow is not handled. Note, arrays would be more efficient

Stack::Stack() : SinglyLinkedList() {}
void Stack::push(int key){
    insert_front(key);
}
int Stack::pop(){
    if (head==nullptr){
        throw std::runtime_error("Stack underflow");
    }
    int val = head->data;
    remove_front();
    return val;
}

Stack::~Stack() {
    //will run default base class SinglyLinkedList destructor
}




