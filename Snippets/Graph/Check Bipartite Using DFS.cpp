//s = source node, graph = adjacency list, n = no. of nodes
//color = vector to store color of nodes. initialized to -1 for all 
//c = color to be passed to next node. Can be 0 or 1
//checks whether graph is bipartite or not using DFS
bool dfs_bipartite(int s, set<int> *graph, int n, vector<int> *color, int c)
{
    (*color)[s] = c;
    bool bipartite = true;
    for(auto itr = graph[s].begin(); itr != graph[s].end(); ++itr)
    {
        if((*color)[*itr] == -1)
        {
            bipartite = dfs_bipartite(*itr, graph, n, color, 1-c);
            if(bipartite == false)
            return false;
        }
        else if((*color)[*itr] == c)
            return false;
    }
    return bipartite;
}