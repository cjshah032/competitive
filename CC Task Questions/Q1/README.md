####Input Format:

First line contains two integers n and k. n lines follow. Each line has two space separated integers representing the x and y coordinates of the points.

Logic Behind Solution:

If we consider all the possible edges from each point to every other point, it becomes a dense graph. Since we need to maximise the minimum distance between any two points from different subsets, it will be best to identify the shortest edges and put the endpoints in one subset. Thus it converts to a Minimum Spanning Forest problem. Minimum Spanning Forest is made using the modified Kruskal's algorithm and the next least edgelength which does not belong to the same subset is the answer q.

Complexity:

1. Space Complexity: The code uses parent array in DisjointSets data structure which is space O(n). The dists vector takes up space O(n^2). Thus total Space complexity is O(n + n^2) ~ O(n^2).

2. Time complexity: One loop to initialise parent array in ds - O(n). Another loop to calculate and store the distances between each two points - O(n^2). Sorting - O(nlogn) and finally the Kruskals algorithm takes O(ElogV) = O(n(n-1)logn) ~ O(n^2*logn). Hence total time complexity is O(n^2(1+logn)).
