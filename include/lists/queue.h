#ifndef QUEUE_H
#define QUEUE_H
#include "lists/singly_linked_list.h"

class Queue : public SinglyLinkedList { 
private:
    int capacity;
    int len;
public: 
    Queue(); //default constructor - infinite capacity
    Queue(int n); //bounded capacity
    void enqueue(int key);
    int dequeue();
    int size() const; //promise we do not modify
    ~Queue(); 
};

#endif