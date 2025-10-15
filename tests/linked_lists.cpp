#include "lists/singly_linked_list.h"
#include <vector>
#include <iostream>
#include <functional>


void run_experiment(const std::string& msg, SinglyLinkedList& list, const std::function<void(SinglyLinkedList&)>& test_fn) {
    std::cout << "======= BEGIN EXPERIMENT: " << msg << " =======" << std::endl;
    test_fn(list);  // Run the passed-in function on the list
    std::cout << "======== END EXPERIMENT: " << msg << " ========" << std::endl;
}

void test_insertions(SinglyLinkedList& list){
    list.print();
    list.insert_back(777);
    list.print();
    list.insert_front(17);
    list.print();
    list.insert_pos(-4,1);
    list.print();
    list.insert_pos(-1337,6);
    list.print();
    list.insert_pos(-2666,0);
    list.print();
    list.insert_pos(-345,9); //same ass insert_back
    list.print();
    //list.insert_pos(-345,1000); //same ass insert_back
    
    return;
}

void test_searches(SinglyLinkedList& list){
    list.print();
    std::cout << "search result for 3: address" << list.search(3) << std::endl;
    std::cout << "search result for 3: value" << *(int *)list.search(3) << std::endl;
    std::cout << "search result for -12: not present" << list.search(-12) << std::endl;
    return;
}

void test_removals(SinglyLinkedList& list){
    std::cout << "removing first element..." << std::endl;
    list.remove_front();
    list.print();
    list.insert_front(17);

    std::cout << "removing last element..." << std::endl;
    list.remove_end();
    list.print();
    list.insert_front(777);

    std::cout << "removing key = 3..." << std::endl;
    int FLAG = list.remove(3);
    std::cout << "success flag becomes: " << FLAG << std::endl;
    list.print();
    
    std::cout << "removing key = 4..." << std::endl;
    FLAG = list.remove(4);
    std::cout << "success flag becomes: " << FLAG << std::endl;
    list.print();

    std::cout << "removing key = 777..." << std::endl;
    FLAG = list.remove(777);
    std::cout << "success flag becomes: " << FLAG << std::endl;
    list.print();
}


int main(){
    std::cout << "Testing vector constructor and insertion methods" << std::endl;
    std::vector<int> vector_to_construct = {1,2,3,4};
    SinglyLinkedList list = SinglyLinkedList(vector_to_construct);
    
    run_experiment("INSERTIONS",list,test_insertions);
    run_experiment("SEARCHES",list,test_searches);
    run_experiment("REMOVALS",list,test_removals);
    
    std::cout << "Testing integer constructor and insertion methods" << std::endl;
    list = SinglyLinkedList(14); //destructor should free one element due to tmp [14]. Reassignment should free 6 elements
    /*
    this would call the copy assignment operation, which without implementation introduces leaks. 
    Understand it like this: 
    1. "reassignment" would create a temporary list object containing Node(14)
    2. Delete old list contents
    3. assign tmp object to "list";
    4. destruct tmp object <- this is problematic, if the copy is shallow this will delete head which list points to -> dangerous
    
    Solutions: 
    1. don't redefine same variable (but we learn very little from doing this).
    2. implement (deep) copy constructor + overload copy assignment operator (maybe we learn a bit more, and it would make for a cleaner library. So let's do that!)
    
    basically the copy constructor is called when creating a new object from an existing one: 
    SinglyLinkedList list1({1, 2, 3});
    SinglyLinkedList list2 = list1;  // ← copy constructor is called here

    or in pythonic fashion:
    list1 = LinkedList([1, 2, 3])
    list2 = copy.deepcopy(list1)  # ← like calling the copy constructor
    */
    list.insert_back(777);
    list.print();
    list.insert_front(17);
    list.print();
    std::cout << "Testing empty constructor and insertion methods" << std::endl;
    list = SinglyLinkedList(); //destructor should free 0 elements because tmp = []
    list.insert_front(17);
    list.print();
    //check reassignment
    list = list; 
    std::cout << "search result " << list.search(777) << std::endl;
    
    
    return 0;
}