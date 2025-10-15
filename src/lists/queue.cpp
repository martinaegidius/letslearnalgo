#include "lists/queue.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

//a queue implementation using singly linked list. As such, overflow is not handled. Note, arrays would be more efficient

Queue::Queue() : SinglyLinkedList() {
    capacity = -1;
    len = 0;
}
Queue::Queue(int n) : SinglyLinkedList() {
    capacity = n;
    len = 0;
}

void Queue::enqueue(int key){
    if (capacity!=-1 && len==capacity){
        std::ostringstream oss;
        oss << "Queue overflow, maximal queue capacity is " << capacity;
        throw std::runtime_error(oss.str());
    }
    insert_back(key);
    len += 1;
}

int Queue::dequeue(){
    if (head==nullptr){
        throw std::runtime_error("Queue underflow"); //could also just do nothing instead, depends on use
    }
    int val = head->data;
    remove_front();
    len -= 1;
    return val;
}

int Queue::size() const {
    return len;
}

Queue::~Queue() {
    //will run default base class SinglyLinkedList destructor
}




