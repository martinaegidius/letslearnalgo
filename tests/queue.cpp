#include "lists/queue.h"
#include <vector>
#include <iostream>
#include <functional>


void run_experiment(const std::string& msg, Queue& queue, const std::function<void(Queue&)>& test_fn) {
    std::cout << "======= BEGIN EXPERIMENT: " << msg << " =======" << std::endl;
    test_fn(queue);  // Run the passed-in function on the queue
    std::cout << "======== END EXPERIMENT: " << msg << " ========" << std::endl;
}

void test_queue(Queue& queue){
    queue.print();
    queue.enqueue(777);
    queue.print();
    std::cout << "current queue size: " << queue.size() << std::endl;
    queue.print();
    queue.enqueue(17);
    std::cout << "current queue size: " << queue.size() << std::endl;
    queue.print();
    queue.enqueue(4);
    queue.print();
    std::cout << "current queue size: " << queue.size() << std::endl;
    
    queue.enqueue(1337);
    queue.print();
    std::cout << "current queue size: " << queue.size() << std::endl;
    
    int output;
    output = queue.dequeue();
    std::cout << "dequeue returned " << output << std::endl;
    output = queue.dequeue();
    std::cout << "dequeue returned " << output << std::endl;
    output = queue.dequeue();
    std::cout << "dequeue returned " << output << std::endl;
    output = queue.dequeue();
    //queue.insert_pos(-345,1000); //same ass insert_back
    
    return;
}

void test_searches(Queue& queue){
    queue.enqueue(4);
    queue.enqueue(3);
    queue.print();
    std::cout << "search result for 3: address" << queue.search(3) << std::endl;
    std::cout << "search result for 3: value" << *(int *)queue.search(3) << std::endl;
    std::cout << "search result for -12: not present" << queue.search(-12) << std::endl;
    return;
}

int main(){
    std::cout << "Testing vector constructor and insertion methods" << std::endl;
    Queue queue = Queue();
    run_experiment("QUEUE",queue,test_queue);
    run_experiment("LIST-SEARCHES",queue,test_searches);
    
    Queue limited_queue = Queue(2);
    run_experiment("CAPACITY LIMITED QUEUE",limited_queue,test_queue);
    run_experiment("LIST-SEARCHES",limited_queue,test_searches);
    
    return 0;
}