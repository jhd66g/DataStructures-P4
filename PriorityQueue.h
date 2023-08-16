#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>

using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::runtime_error;

struct Node{
    string vert1;
    string vert2;
    unsigned int weight;
    Node(): vert1{""}, vert2{""}, weight{0}{}
    Node(string v1, string v2, unsigned int w): vert1{v1}, vert2{v2}, weight{w}{}
    Node(string v1, unsigned int w): vert1{v1}, vert2{""}, weight{w}{}
};

#ifndef HashTable_H
#define HashTable_H

class HashTable{
    private:
        Node* arr;
        unsigned int load;

    public:
        HashTable(); // constructor
        HashTable (unsigned int ); // overloaded constructor
        ~HashTable(); // destructor


        unsigned int hash(const string & ); // hash function
        void add(Node ); // adds item to hash table
        bool find(string ); // finds string in dictionary, returns true if found
        bool isPrime(int ); // checks if num is prime
        void nextLargestPrime(unsigned int &); // finds next largest prime
        int probe(int , int ); // probes the hash table
        unsigned int& getWeight(string ); // returns the weight 
        string getVert2(string ); // returns the vert2

        void print(); // prints contents of table

};

#endif 

#ifndef PriorityQueue_h
#define PriorityQueue_h

class PriorityQueue{
    private:
        Node* arr; // need to change to template
        unsigned int size;
        unsigned int load; // keeps track of next open spot

    public:
        // default constructor 
        PriorityQueue();
        // overloaded constructor that takes in size
        PriorityQueue(unsigned int );
        // destructor
        ~PriorityQueue();

        // inserts item into queue
        void insert(Node );
        // tossin for build heap
        void tossIn(Node );
        // builds heap
        void buildHeap();
        // removes top item
        Node pop();
        // checks if heap if full
        bool full();
        // checks if heap is empty
        bool empty();
        // swaps 2 items given their position
        void swap(unsigned int x, unsigned int y);

        // prints heap
        void print();




};

#endif