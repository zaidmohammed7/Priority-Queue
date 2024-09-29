# Priority Queue Project

## Overview
This project implements a priority queue in C++ using a binary search tree (BST). The priority queue allows for the management of elements with associated priorities, enabling the retrieval of the highest priority element. The main program tests the functionalities of the `prqueue` class, allowing users to enqueue, dequeue, peek at the highest priority element, and more.

## Authors
- **Starter code provided by:** Adam T Koehler, PhD - University of Illinois Chicago
- **Student Author:** Zaid Khan Mohammed 

## Files
- **`main.cpp`**: The main program that tests the execution of the priority queue functionalities.
- **`prqueue.h`**: The header file for the `prqueue` class, declaring its structure and member functions.
- **`tests.cpp`**: A testing file using the Catch testing framework to validate the functionality of the priority queue class.

## Features
- **Binary Search Tree Structure**: The priority queue is implemented using a binary search tree, which ensures that elements are ordered based on their priority. Each node in the tree contains:
  - An integer `priority` to determine the order of elements.
  - A value of type `T` to store the actual data.
  - Pointers to left, right, and parent nodes, allowing traversal of the tree.
  - A `link` pointer to handle duplicates with the same priority.

- **Enqueue and Dequeue Operations**:
  - The `enqueue` function inserts new elements in the correct position based on priority. If an element with the same priority exists, it adds it to a linked list of duplicates.
  - The `dequeue` function removes the node with the lowest priority (the leftmost node) and adjusts the tree accordingly.

- **Traversal Methods**:
  - The `begin` and `next` methods enable in-order traversal, allowing sequential access to elements.

- **Memory Management**: The destructor and `clear` functions ensure proper deallocation of memory for the nodes, preventing memory leaks.

## Class Overview
### prqueue
- Implements a priority queue using templates to support various data types (e.g., `int`, `float`, `char`, `string`).
- Provides methods for adding elements (`enqueue`), removing elements (`dequeue`), checking the current highest priority element (`peek`), and converting the queue to a string representation (`toString`).

## Testing
The project includes a suite of tests in `tests.cpp` that uses the **Catch** testing framework. The tests cover various functionalities of the `prqueue` class, ensuring that the implementation behaves as expected across different data types.

### Key Learnings from the Project
- **Understanding Data Structures**: Implementing a priority queue deepened my understanding of how data structures can be utilized to manage elements based on their priorities.
- **Using the Catch Framework**: Increased my familiarity with the Catch testing framework to write and execute unit tests, which helped me ensure the reliability of my code.
- **Importance of Testing**: This project reinforced the value of writing tests, highlighting how they help catch issues early and ensure code correctness throughout development.
