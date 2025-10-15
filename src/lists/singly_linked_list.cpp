#include "lists/singly_linked_list.h"
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

void SinglyLinkedList::insert_front(int k){
    if (head!=nullptr){
        Node* new_head = new Node(k);
        new_head->next = head;
        head = new_head; //update head pointer target
    }
    else {
        head = new Node(k);
        head->next = nullptr;
    }
    return;
}

void SinglyLinkedList::insert_back(int k){
    Node* new_node = new Node(k);
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

void SinglyLinkedList::insert_pos(int key, int idx){
    //insert a key into a list index idx 
    if (idx==0){
        insert_front(key);
        return;
    }
    Node * current = head; 
    int counter = 0;
    while (current!=nullptr && counter<idx-1){
        current = current->next;
        counter++;
    }

    if (current==nullptr){
        std::cerr << "Index out of bounds!\n";
    }
    
    Node * new_node = new Node(key);
    new_node->next = current->next; 
    current->next = new_node;

    
    return; 
}

SinglyLinkedList::Node* SinglyLinkedList::search(int key){
    //returns a pointer to the node holding the key if key is present in list.
    Node* current = head;
    while (current!=nullptr){
        if (current->data==key) return current;
        current = current->next;
    }
    return nullptr;
}

void SinglyLinkedList::remove(Node* addr){
    //Takes address as input, which points to a found element found by using search(key)
    if (addr->next==nullptr){//case: last element
        remove_end();
        return;
    }
    else if (addr==head){
        return remove_front();
        return;
    }

    Node* current = head;
    while (current!=nullptr && current->next!=nullptr && current->next!=addr){
        current = current->next;
    }
    //case: at elem before splice or end of list
    if (current->next==addr){
        if (addr->next!=nullptr){ //case: not end; skip element in addr and link forward
            current->next = addr->next;
            delete addr;
        }
    }
}

void SinglyLinkedList::remove_end(){
    //removes last element from list and deletes node
    if (head==nullptr) return; //case empty
    Node* current = head; 
    if (head->next==nullptr){ //case length one list
        delete head;
        head = nullptr;
        return;
    } 

    while (current->next->next!=nullptr){
        current = current->next;
    }
    delete current->next; //remove last node
    current->next = nullptr;
    return;
}

void SinglyLinkedList::remove_front(){
    if (head==nullptr) return;
    if (head->next==nullptr){
        delete head;
        head = nullptr;
    }
    else {
        Node* new_first = head->next;
        delete head;
        head = new_first;
    }
    return;
}

int SinglyLinkedList::remove(int key){
    //returns 0 if element not found, 1 if element removed
    Node * addr = search(key);
    if (addr!=nullptr){
        remove(addr);
        return 1;
    }
    return 0;
}




void SinglyLinkedList::print() const{
    Node* current = head; 
    std::cout << "[";
    while (current!=nullptr){
        std::cout << current->data;
        if (current->next != nullptr){std::cout << ",";} //case: more elems in list
        current = current->next;
    }
    std::cout << "]" << std::endl;    
}



//copy constructor: construct new object from other object, passed by reference and promised unchanged during construction
//basically just an implementation of a deep-copy
SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other) : head(nullptr){
    Node * current = other.head;
    while (current!=nullptr){
        insert_back(current->data); //insert into list
        current = current->next;
    }
}

SinglyLinkedList& SinglyLinkedList::operator=(const SinglyLinkedList& other) {
    //assignment operator. Replace contents of existing object. Allows changing list contents directly in the same object.
    //goal: clean up old data, copy new data in, return modified object
    if (this==&other) return *this; //check and handle self-assignment with no alteration
    //*this = SinglyLinkedList(other); <- can't do this, as this will call this method again and again -> stack overflow.
    
    //clean up current data in self
    Node * current = head;
    int del_count = 0;
    while (current!=nullptr){
        Node * next = current->next;
        delete current;
        current = next;
        del_count++;
    }
    std::cout << "Assignment operator: Freed " << del_count << " elements" << std::endl;
    head = nullptr;
    //rebuild list as deep-copy of other
    current = other.head;
    while (current!=nullptr){
        insert_back(current->data);
        current = current->next;
    }
    

    return *this;
}


SinglyLinkedList::~SinglyLinkedList()
//loop through list and free all nodes  
{
    Node * current = head;
    int counter = 0;
    while (current!=nullptr){
        Node * next = current->next; //go to next elem
        delete current;
        current = next;
        counter++;
    }
    std::cout << "Destructor: Freed " << counter << " elements" <<std::endl; //note: this is print at reassignment due to destruction of temporary copy
}
