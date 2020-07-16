//s = source node, graph = adjacency list, n = no. of nodes
//checks whether graph is bipartite or not using BFS
bool bfs_bipartite(int s, set<int> *graph, int n)
{
    bool bipartite = true;
    vector<int> color(n, -1);
    queue<int> q; q.push(s);
    color[s] = 0;
    while(!q.empty() && bipartite){
        int u = q.front(); q.pop();
        for(auto itr = graph[u].begin(); itr != graph[u].end(); ++itr)
        {
            if(color[*itr] == -1)
            {
                color[*itr] = 1 - color[u];
                q.push(*itr);
            }
            else if(color[*itr] == color[u])
            {
                bipartite = false;
                break;
            }
        }
    }
    return bipartite;
}