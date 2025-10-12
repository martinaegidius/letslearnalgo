#include "singly_linked_list.h"
#include <iostream>

SinglyLinkedList::Node::Node(int val) : data(val), next(nullptr) {}
SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}
SinglyLinkedList::SinglyLinkedList(int k){
    head = new Node(k);
}
SinglyLinkedList::SinglyLinkedList(const std::vector<int>& v) {
    head = nullptr;
    for (int val : v) {
        insert_back(val);  // Or implement your own logic here
    }
}

void SinglyLinkedList::insert_back(int k){
    Node* new_node = new Node(val);
    if (head==nullptr){
        head = new_node;
        return;
    }
    
    Node* current = head; 
    while (current->next!=nullptr){
        current = current->next;
    }
    current->next = new_node;
    return;
}

void SinglyLinkedList::print(){
    Node* current = head; 
    cout << "[";
    while (current->next!=nullptr){
        cout << current->val << " ";
        current = current->next;
    }
    cout << "]";
}






public: 
    SinglyLinkedList(); //constructor
    ~SinglyLinkedList(); //deconstructor 
    bool search(int k);
    void insert(int k) const; //const supports immutables
    void remove(int k);
    void print() const; 
    void insert_front(int val);
    void insert_back(int val);
};


#endif
