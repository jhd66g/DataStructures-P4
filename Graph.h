#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <limits> 

using std::ifstream;
using std::cout;
using std::endl;
using std::string;

struct adjNode{
    string name;
    unsigned int weight;
    adjNode* next;
    adjNode(): name{}, weight{}, next{nullptr}{}
    adjNode(string n, unsigned int w): name{n}, weight{w}, next{nullptr}{}
};

#ifndef AdjList_h
#define AdjList_h

class adjList {
    private:
        adjNode *head;
        adjNode *tail;

    public:
        adjList(); // constructor
        ~adjList(); // destructor

        adjNode* getHead(); // returns head
        void push_back(adjNode* ); // adds item to the back

        void print(); // prints contents of list
};

#endif

#ifndef Graph_h
#define Graph_h

class Graph{
    private:
        unsigned int edges; 
        unsigned int vertices; 
        unsigned int size;
        adjList* arr;

    public:
        // default constructor 
        Graph();
        // overloaded constructor that takes in size
        Graph(unsigned int );
        // destructor
        ~Graph();

        // returns number of (non-sink) vertices 
        unsigned int& numVerts();
        // returns number of edges 
        unsigned int& numEdges();
        // hash function
        unsigned int hash(const string & ); 
        // checks if num is prime
        bool isPrime(int ); 
        // finds next largest prime
        unsigned int nextLargestPrime(unsigned int ); 
        // probes the hash table
        int probe(int , int ); 

        // finds adjNode
        adjNode* find(string );
        // adds edge to list
        void addEdge(string v, string n, unsigned int w);
        // prints graph in adjacency 
        void print();

};

#endif