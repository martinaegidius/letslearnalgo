#include "lists/stack.h"
#include <vector>
#include <iostream>
#include <functional>


void run_experiment(const std::string& msg, Stack& stack, const std::function<void(Stack&)>& test_fn) {
    std::cout << "======= BEGIN EXPERIMENT: " << msg << " =======" << std::endl;
    test_fn(stack);  // Run the passed-in function on the list
    std::cout << "======== END EXPERIMENT: " << msg << " ========" << std::endl;
}

void test_stack(Stack& stack){
    stack.print();
    int output; 
    stack.push(1);
    stack.print();
    stack.push(4);
    stack.print();
    output = stack.pop();
    std::cout << "popped value " << output << std::endl;
    stack.print();
    output = stack.pop();
    std::cout << "popped value " << output << std::endl;
    stack.print();

    //this should throw an exception
    output = stack.pop();
    return;
}

void test_searches(Stack& stack){
    stack.push(4);
    stack.push(3);
    std::cout << "testing searches for Stack: ";
    stack.print();
    std::cout << "search result for 3: address" << stack.search(3) << std::endl;
    std::cout << "search result for 3: value" << *(int *)stack.search(3) << std::endl;
    std::cout << "search result for -12: not present" << stack.search(-12) << std::endl;
    return;
}


int main(){
    Stack stack = Stack();
    run_experiment("Stack-OPERATIONS",stack,test_stack);
    run_experiment("SEARCHES",stack,test_searches);
    
    return 0;
}