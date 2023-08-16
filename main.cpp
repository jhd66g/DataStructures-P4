#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <limits>
#include "Graph.h"
#include "PriorityQueue.h"

using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::istringstream;

unsigned int countQueries(ifstream& x); // gets max number of potential nodes

void dijkstra(Graph & graph, string start, string end); // calculates the shortest distance from start to end

int main(int argc, char* argv[]){
    std::ios_base::sync_with_stdio(false);
    auto t1 = std::chrono::steady_clock::now();

    // getting length
    cout << "Testing graph class ..." << endl;
    ifstream fstr(argv[1]);
    unsigned int c = countQueries(fstr);
    Graph g(c);
    string first;
    string last;
    string trash;

    // intialization
    fstr >> first >> last >> trash; // 1st 3 strings
    string v1; 
    string v2;
    unsigned int w;
    while (fstr >> v1 >> v2 >> w){
        g.addEdge(v1, v2, w);
    }

    // dijkstra's algorithm
    dijkstra(g, first, last);

    // timing
    auto t2 = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds> (t2 - t1).count();
    cout << "Time : " << duration << " nanoseconds" << endl;

    return 0;
}

unsigned int countQueries(ifstream& x){
    unsigned int count{0};
    string trash;
    x >> trash >> trash >> trash; // disregrad 1st 3 strings
    string s1; 
    string s2;
    unsigned int n;
    while (x >> s1 >> s2 >> n){
        count ++;
    }
    x.clear();
    x.seekg(0, std::ios::beg);
    return count;
}

void dijkstra(Graph & graph, string start, string end){
    // initialize priority queue and way of checking if vertices have been checked
    PriorityQueue pq(graph.numEdges());
    pq.tossIn(Node(start, 0));
    HashTable distances(graph.numVerts());
    
    // loop through pq
    while (!pq.empty()){
        // dequeue vertex with minimum distance
        Node minNode = pq.pop();
        adjNode* curr = graph.find(minNode.vert1);
        if (!distances.find(minNode.vert1)){
            distances.add(minNode);
        }
        while (curr != nullptr){
            if (!distances.find(curr->name)){
                Node n(curr->name, minNode.vert1, curr->weight + minNode.weight);
                pq.tossIn(n);
            }
            curr = curr->next;
        }
        pq.buildHeap();
        if (minNode.vert1 == end){
            break;
        }
    }
    
    // creating path output
    string path{end};
    string s{end};
    while (path.substr(0, start.length()) != start){
        s = distances.getVert2(s);
        path.insert(0, s + " ");
    }

    cout << "Path: " << path << endl;
    cout << "Cost: " << distances.getWeight(end) << endl;


}