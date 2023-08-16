#include "PriorityQueue.h"

// constructor
HashTable::HashTable(): load{10} {
    nextLargestPrime(load);
    arr = new Node [load];
} 

// overloaded constructor
HashTable::HashTable (unsigned int n): load{n}{
    nextLargestPrime(load);
    arr = new Node [load];
}

// destructor
HashTable::~HashTable(){
    delete [] arr;
} 

// hash function
unsigned int HashTable::hash(const string & key){
    unsigned int hashVal = 0;
    for (char ch: key){
        hashVal = 37*hashVal + ch;
    }
    return hashVal % load;
}

// adds item to hash table
void HashTable::add(Node d){
    unsigned int location = hash(d.vert1);
    int i = 0;
    while (arr[location].vert1 != "" && arr[location].vert1 != d.vert1){
        i++;
        location = probe(location, i);
    }
    arr[location] = d;
}

// finds string in table, returns true if found
bool HashTable::find(string s){
    unsigned int location = hash(s);
    int i = 0;
    while (arr[location].vert1 != "" && arr[location].vert1 != s) {
        i++;
        location = probe(location, i);
    }
    if (arr[location].vert1 == s){
        return true;
    } 
    else{
        return false;
    }
}

// checks if num is prime
bool HashTable::isPrime(int n) {
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
void HashTable::nextLargestPrime(unsigned int &n){
    n *= 2;
    while (!isPrime(n)){
        n++;
    }
    return;
}

// probes the hash table
int HashTable::probe(int key, int i) {
    return (key + i*i) % load;
}

// returns the weight 
unsigned int& HashTable::getWeight(string s){
    unsigned int location = hash(s);
    int i = 0;
    while (arr[location].vert1 != "" && arr[location].vert1 != s) {
        i++;
        location = probe(location, i);
    }
    if (arr[location].vert1 == s){
        return arr[location].weight;
    } 
    else{
        throw runtime_error("string not found");
    }
} 

// returns the vert2
string HashTable::getVert2(string s){
    unsigned int location = hash(s);
    int i = 0;
    while (arr[location].vert1 != "" && arr[location].vert1 != s) {
        i++;
        location = probe(location, i);
    }
    if (arr[location].vert1 == s){
        return arr[location].vert2;
    } 
    else{
        throw runtime_error("string not found");
    }
}

// prints contents of table
void HashTable::print(){
    for (int i = 0; i < load; i++){
        cout << i << "| " << arr[i].vert1 << " " << arr[i].vert2 << " " << arr[i].weight << endl;
    }
    return;
}

// default constructor 
PriorityQueue::PriorityQueue(): size{5}, load{1}{
    arr = new Node[size];
}

// overloaded constructor that takes in size
PriorityQueue::PriorityQueue(unsigned int s): size{s+1}, load{1}{
    arr = new Node[size];
}

// destructor
PriorityQueue::~PriorityQueue(){
    delete [] arr;
}

// lazily inserts item into queue
void PriorityQueue::insert(Node n){
    tossIn(n);
    // percolate up
    int index = load - 1; 
    while (index > 1 && arr[index].weight < arr[index/2].weight){
        swap(index, index/2); 
        index /= 2; // update index
    }
}

// tossin for build heap
 void PriorityQueue::tossIn(Node n){
    // if heap is full throw
    if (full()){
        throw runtime_error("heap is full");
    }
    arr[load] = n;
    load++;
 }

// builds heap
void PriorityQueue::buildHeap(){
    // start at back of the heap 
    for (int i = load / 2; i >= 1; i--){
        int index = i; 
        // bubble down
        while (index * 2 < load){
            int child = index * 2;
            if ((child + 1 < load) && (arr[child + 1].weight < arr[child].weight)){
                child ++;
            }
            if (arr[child].weight < arr[index].weight){
                swap(child, index);
                index = child;
            }
            else{
                break;
            }
        }
    }
}

// removes top item
Node PriorityQueue::pop(){
    if (load == 1){
        throw runtime_error("heap is empty");
    }
    Node min = arr[1]; // store former top
    arr[1] = arr[load-1]; // put item in back to the front
    load --;
    // percolate down
    int index = 1;
    while (index * 2 < load){
        int child = index * 2;
        if ((child + 1 < load) && arr[child + 1].weight < arr[child].weight){
            child ++;
        }
        if (arr[child].weight < arr[index].weight){
            swap(child, index);
            index = child;
        }
        else{
            break;
        }
    }
    return min;
}

// checks if heap if full
bool PriorityQueue::full(){
    return (load >= size);
}

// checks if heap is empty
bool PriorityQueue::empty(){
    return load == 1;
}

// swaps 2 items given their position
void PriorityQueue::swap(unsigned int x, unsigned int y){
    Node temp = arr[y];
    arr[y] = arr[x];
    arr[x] = temp;
}

// prints heap
void PriorityQueue::print(){
    for (int i = 0; i < load; i ++){
        cout << i << "| " << arr[i].vert1 << " " << arr[i].vert2 << " " << arr[i].weight << endl;
    }
}