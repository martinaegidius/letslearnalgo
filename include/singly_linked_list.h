#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

class SinglyLinkedList {
private: 
    struct Node {
        int data;
        Node* next; 
        Node(int val); //constructor definition
    }
    Node* head;     

public: 
    SinglyLinkedList(); //default constructor   
    SinglyLinkedList(int k);
    SinglyLinkedList(const std::vector<int>& v); 
    ~SinglyLinkedList(); //deconstructor 
    //bool search(int k);
    //void insert(int k) const; //const supports immutables
    //void remove(int k);
    void print() const; 
    //void insert_front(int val);
    void insert_back(int val);
};


#endif
