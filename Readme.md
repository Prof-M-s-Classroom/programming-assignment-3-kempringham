[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Kimmy Empringham

## Description
Briefly describe what your program does and how the code is structured.

The purpose of this program is to find a spanning tree of a weighted, connected, undirected graph with a minimum total 
edge weight, connecting all the vertices without any cycles. The Prim MST is implemented using a min heap and an 
adjacency matrix.

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
| Insert in MinHeap    | O(N)            |
| Extract Min          | O(log(N))       |
| Decrease Key         | O(log(N))       |
| Prim’s MST Overall   | O(Nlog(N))      |

_Explain why your MST implementation has the above runtime._

Insert in MinHeap is O(N) because it minheapifies
Extract min is O(log(N)) because it upheaps
Decrease key is O(log(N)) because it upheaps
Prim's MST overall is O(N(log(N))) because

## Test Case Description
Test 1:
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
g.addEdge(0,4,3);
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
