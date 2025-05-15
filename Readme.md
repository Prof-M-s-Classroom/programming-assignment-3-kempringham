[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Kimmy Empringham

## Description
The purpose of this program is to implement Prim's Algorithm using min heap and an adjacency matrix. We want to
find a spanning tree of a weighted, connected, undirected graph with the minimum total edge weight to connect all the 
vertices without any cycles. We use 2 files, one to create the min heap and another to create the adjacency matrix and 
find the minimum spanning tree using Prim's. We also have the main to create a graph and test Prim's algorithm.

## Files
- graph.h
- heap.h
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis

| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(log(N))       |
| Extract Min          | O(log(N))       |
| Decrease Key         | O(log(N))       |
| Prim’s MST Overall   | O(V^2)          |

Insert in MinHeap is O(log(N)) because the new vertex is inserted at the bottom of the heap and up heaped to maintain the
heap property. When it is up heaped, it is moved up a whole level everytime. Extract min is O(log(N)) because the minimum 
vertex gets replaced by the bottom vertex and down heaps(min heapifies). When it down heaps, it moved down a whole level 
everytime. Decrease key is O(log(N)) because it up heaped to maintain the heap property. When it is up heaped, it is 
moved up a whole level everytime. Prim's MST overall is O(V^2) because it uses an adjacency matrix. We have to loop 
through the entire row of the matrix for every vertex.

## Test Case Description
Test 1
Input:  
Graph g(5);
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.addEdge(3, 4, 9);
g.primMST();

Output:
0 -- 1 (2)
1 -- 2 (3)
0 -- 3 (6)
1 -- 4 (5)
Total Cost: 16

Test 2:
Input:
Graph g(6);
g.addEdge(0, 2, 4);
g.addEdge(0, 3, 6);
g.addEdge(0, 4, 3);
g.addEdge(1, 3, 2);
g.addEdge(3, 2, 7);
g.addEdge(3, 4, 6);
g.addEdge(4, 5, 3);
g.addEdge(5, 2, 1);
g.addEdge(5, 4, 3);

g.primMST();

Output:
0 -- 4 (3)
4 -- 5 (3)
5 -- 2 (1)
0 -- 3 (6)
3 -- 1 (2)
Total Cost: 15

Test 3:
Graph g(3);
g.addEdge(0, 1, 10);
g.addEdge(0, 1, 5);
g.addEdge(1, 2, 1);
g.primMST();

0 -- 1 (5)
1 -- 2 (1)
Total Cost: 6

Test 4:
Input:
Graph g(0);
g.primMST();

Output:
Total Cost: 0

The first additional test I tried(Test 2) was similar to the first, but I wanted make sure that it wasn't working by 
coincidence. The next test I tried(Test 3) was to check the edge case of updating the weight of an edge. I wanted to 
make sure that the key value would decrease, which the output shows that it did so properly. The third additional test 
I did(Test 4) was to test the edge case of having an empty graph.

Challenges faced
The main challenge I faced is that I had a misunderstanding of Prim's algorithm. I got it mixed up with the shortest 
path algorithms rather than the minimum spanning tree algorithms.
