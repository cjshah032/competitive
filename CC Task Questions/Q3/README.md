Input Format:

First line contains single integer n. Next n lines contain two integers a and b (0 <= a,b < n) representing an edge between node a and b.

Logic Behind Solution:

A tree is a graph with no cycles. Thus it has exactly n-1 edges for n vertices. Now, since there are n edges and n vertices, it means there must be a cycle somewhere. So the program runs a tweeked dfs to detect cycle and prints the two nodes value where there is extra edge. The program exits after finding this.

Complexity:

1. Space: The whole program maintains one Adjacency list (O(E + V) = O(n)) and two arrays of length n (O(n)). Thus the total space complexity is O(n).

2. Time: DFS takes O(V+E) ie O(n) while initialising parent and visited arrays take O(n). Thus total time complexity is O(n).
