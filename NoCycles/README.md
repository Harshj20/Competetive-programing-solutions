# Assigning Directions to Undirected Edges

This program solves the problem of assigning directions to undirected edges in a graph to avoid forming cycles.

## Problem Description

Given a graph with directed and undirected edges, the task is to assign directions to undirected edges such that cycles are not formed in the graph.

### Input Format

- The first line of the input contains an integer T, the number of test cases.
- Each test case is described as follows:
  - The first line of each test case contains three integers: N, M, and K.
    - N represents the number of nodes in the graph.
    - M represents the number of directed edges.
    - K represents the number of undirected edges.
  - The next M lines contain two integers each, representing directed edges from the first node to the second node.
  - The next K lines contain two integers each, representing undirected edges between the first node and the second node.

### Output Format

- For each test case, the program outputs a string consisting of 0's and 1's.
- Each character in the string corresponds to an undirected edge, in the same order as the edges were given in the input.
  - If the character is 0, it means that the direction of the edge is the same as given in the input.
  - If the character is 1, it means that the direction of the edge is the opposite of the input.
- The output for each test case is printed on a new line.

### Example

Input:
```
2
3 1 2
1 2
1 3
2 3
3 1 2
1 2
1 3
2 3
```

Output:
```
Case #1
10
Case #2
01
```


## Implementation Details

The program follows the following steps to solve the problem:

1. Read the number of test cases, T, from the input.
2. Iterate T times for each test case:
   1. Read the number of nodes N, the number of directed edges M, and the number of undirected edges K.
   2. Create an adjacency list to represent the graph.
   3. Read the M directed edges and add them to the adjacency list.
   4. Read the K undirected edges and store them as a list of edges.
   5. Iterate through each undirected edge:
      1. Add the edge to the adjacency list temporarily.
      2. Check if the addition of the edge creates a cycle using a depth-first search (DFS) algorithm.
      3. If a cycle is found, assign direction 1 to the edge; otherwise, assign direction 0.
      4. Remove the edge from the adjacency list.
   6. Print the list of directions as a string.
3. End of the program.

## How to Run

1. Ensure you have a C++ compiler installed (e.g., g++).
2. Save the code in a file named "main.cpp".
3. Open a terminal and navigate to the directory containing the code file.
4. Compile the code using the following command:
5. Run the program using the command:
6. Enter the input as described in the input format.
7. The program will output the results for each test case.

Feel free to modify the code and input according to your needs.
