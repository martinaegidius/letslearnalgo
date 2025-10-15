#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <vector>

class SinglyLinkedList {
protected: 
    struct Node {
        int data;
        Node* next; 
        Node(int val); //constructor definition
    };
    Node* head;     

public: 
    SinglyLinkedList(); //default constructor   
    SinglyLinkedList(int k);
    SinglyLinkedList(const std::vector<int>& v); 
    void insert_front(int val);
    void insert_back(int val);
    Node* search(int k);
    void insert(int k) const; //const supports immutables
    void insert_pos(int key, int idx);
    void remove(Node* addr);
    int remove(int key);
    void remove_end();
    void remove_front();
    void print() const; 
    
    
    //rule of three: destructor, copy constructor, copy assignment operator
    ~SinglyLinkedList(); 
    SinglyLinkedList(const SinglyLinkedList& other); 
    SinglyLinkedList& operator=(const SinglyLinkedList& other);
};


#endif
