# DataStructures-P4
Dykstra's Algorithm
This repository contains a C++ implementation of Dijkstra's Algorithm, which is a graph search algorithm that solves the single-source shortest path problem for a graph with non-negative edge path costs, producing a shortest-path tree.

## Files Overview

### Graph.h/cpp
Defines and implements a `Graph` class which encapsulates a graph representation and related functionality. It utilizes an adjacency list and hash table to implement key graph functionalities such as adding edges, finding nodes, and printing the graph.

### PriorityQueue.h/cpp
Defines and implements the `HashTable` and `PriorityQueue` classes. The `HashTable` class is utilized to store and find vertex data in a hash table. `PriorityQueue` is implemented to manage graph vertices based on their distances in a min-heap, ensuring that the vertex with the smallest distance is always at the top.

## Build and Run
To build and run the project, follow the below steps (assuming `g++` compiler is installed):

1. Compile the source files: g++ -O3 -std=c++20 main.cpp PriorityQueue.cpp Graph.cpp
2. Run the compiled binary: ./a.out [filename.txt]

## Usage

To utilize the implemented graph and priority queue structures, create an instance of the `Graph` and `PriorityQueue` classes, and use the provided member functions to interact with them. Here is a brief overview of available functionality:

### Graph
- `addEdge(string v, string n, unsigned int w)`: Add an edge from vertex `v` to vertex `n` with weight `w`.
- `print()`: Print the adjacency list of the graph.

### PriorityQueue
- `insert(Node n)`: Insert node `n` into the priority queue.
- `pop()`: Remove and return the top element from the priority queue.
- `full()`: Check if the priority queue is full.
- `empty()`: Check if the priority queue is empty.

## Algorithm
Dijkstra's Algorithm itself is not explicitly implemented in the provided code snippets. You'll typically utilize both the `Graph` and `PriorityQueue` classes to implement the algorithm. Refer to Dijkstra's Algorithm pseudocode or available implementations to build upon this project.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to
