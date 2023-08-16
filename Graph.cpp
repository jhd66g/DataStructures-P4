#include "Graph.h"

// constructor
adjList::adjList(): head{nullptr}, tail{nullptr}{} 

// destructor
adjList::~adjList(){
    adjNode *curr = head;
    while (head != nullptr) {
        head = head->next;
        delete curr;
        curr = head;
    }
    delete head;
}

// returns head
adjNode* adjList::getHead(){
    return head;
}

// adds node to the back of adjList
void adjList::push_back(adjNode* a) {
    if (head == nullptr) {
        head = a;
        tail = a;
    }
    else {
        tail->next = a;
        tail = a;
    }
}

// prints contents of list
void adjList::print(){
    adjNode* current = head;
    while (current != nullptr) {
        cout << current->name << " " << current->weight << " -> ";
        current = current->next;
    }
    cout << endl;
} 

// default constructor 
Graph::Graph(): edges{5}, vertices{0}, size{11}{
    arr = new adjList[size];
}

// overloaded constructor that takes in size
Graph::Graph(unsigned int s): edges{s}, vertices{0}{
    size = nextLargestPrime(edges);
    arr = new adjList[size];
}

// destructor
Graph::~Graph(){
    delete[] arr;
}

// returns number of (non-sink) vertices 
unsigned int& Graph::numVerts(){
    return vertices;
}

// returns number of edges 
unsigned int& Graph::numEdges(){
    return edges;
}

// hash function
unsigned int Graph::hash(const string & key){
    unsigned int hashVal = 0;
    for (char ch: key){
        hashVal = 37*hashVal + ch;
    }
    return hashVal % size;
}

// checks if num is prime
bool Graph::isPrime(int n){
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// finds next largest prime
unsigned int Graph::nextLargestPrime(unsigned int n){
    n *= 2;
    while (!isPrime(n)){
        n++;
    }
    return n;
} 

// probes the hash table
int Graph::probe(int k, int i){
    return (k + i*i) % size;
}

// finds adjNode
adjNode* Graph::find(string start){
    unsigned int location = hash(start);
    int i = 0;
    while (arr[location].getHead() != nullptr && 
    (arr[location].getHead())->name != "" && (arr[location].getHead())->name != start){
        i++;
        location = probe(location, i);
    }
    if (arr[location].getHead() != nullptr && (arr[location].getHead())->name == start){
        return arr[location].getHead();
    }
    return nullptr;
}

// adds edge to list
void Graph::addEdge(string v, string n, unsigned int w){
    unsigned int location = hash(v);
    adjNode* newNode = new adjNode(n, w);
    int i = 0;
    while (arr[location].getHead() != nullptr && 
    (arr[location].getHead())->name != "" && (arr[location].getHead())->name != v){
        i++;
        location = probe(location, i);
    }
    if (arr[location].getHead() != nullptr && (arr[location].getHead())->name == v){
        arr[location].push_back(newNode);
    }
    else{
        adjNode* first = new adjNode(v, 0);
        arr[location].push_back(first);
        arr[location].push_back(newNode);
        vertices ++;
    }
    
}

// prints graph in adjacency 
void Graph::print(){
    for (int i = 0; i < size; i++){
        if (arr[i].getHead() != nullptr){
            cout << i << "| ";
	        arr[i].print();
        }
    }
}