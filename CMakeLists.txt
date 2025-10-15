cmake_minimum_required(VERSION 3.15)
project(LETSLEARNALGO VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include) #is a global import to the compiler include path. Only do this for small projects

# ----------------------- 
# Library: Linked Lists 
# -----------------------

#make a static library called linked_list based on class definition and header 
add_library(linked_list
    src/lists/singly_linked_list.cpp
) 

target_include_directories(linked_list PUBLIC include)

# ----------------------- 
# Executables for week 4: Linked Lists 
# -----------------------

#create test executable linked_list_tests from tests/linked_lists.cpp 
add_executable(linked_list_tests tests/linked_lists.cpp)
target_link_libraries(linked_list_tests PRIVATE linked_list) #private because we don't want to pass compile definitions and directories.

#stack implementation which links to singly_linked list library
add_library(stack src/lists/stack.cpp)
target_include_directories(stack PUBLIC include)
target_link_libraries(stack PRIVATE linked_list) #link against linked_list library liblinked_list.a
add_executable(stack_tests tests/stack.cpp)
target_link_libraries(stack_tests PRIVATE stack)

#queue implementation which links to singly_linked list library
add_library(queue src/lists/queue.cpp)
target_include_directories(queue PUBLIC include)
target_link_libraries(queue PRIVATE linked_list) #link against linked_list library liblinked_list.a
add_executable(queue_tests tests/queue.cpp)
target_link_libraries(queue_tests PRIVATE queue)



# ----------------------
# (Later) Executable for week 5: graphs
# ----------------------
#add_library(queue src/lists/queue.cpp)
#target_include_directories(queue PUBLIC include)
#add_executable(tests/queue.cpp)
#target_link_libraries(week5 PRIVATE queue)
