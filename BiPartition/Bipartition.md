You are given an undirected, connected graph G(V, E).
G is said to be bipartite if V can be partitioned into two sets V1 & V2, such that all edges of G are between sets V1 and V2. Write a program that takes G as input and checks if the graph is bipartite or not. If it is Bipartite, your program should print "YES" followed by V integers(1 or 2) indicating which set each vertex belongs to. Vertex 0 must belong to set 1.
If the Graph is not Bipartite, print "NO". Your algorithm should work in O(|V| + |E|) time.
###### Input format
First line contains V, the number of vertices. Second line contains E, the number of edges. Then E lines follow. Each line contains two integers a and b indicating that a bidirectional edge exists between Vertex a and Vertex b.

###### Output Format
If it is Bipartite, your program should print "YES". Then in a new line print V integers(1/2) indicating which set each vertex belongs to. Vertex 0 must belong to set 1. If the Graph is not Bipartite, print "NO".

###### Sample Input 0
~~~
7
8
6 3
1 5
1 2
0 5
4 2
6 0
2 3
4 5
~~~
###### Sample Output 0
~~~
YES
1
1
2
1
1
2
2
~~~

##### Code in C 
(only for connected graph)

