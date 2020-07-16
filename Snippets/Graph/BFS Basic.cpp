//s = source node, graph = adjacency list, visited = array to check visited
void bfs(int s, set<int> *graph, bool *visited)
{
    queue<int> q; q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto itr = graph[u].begin(); itr != graph[u].end(); itr++)
        {
            if(visited[*itr] == true)
            continue;
            else {
                visited[*itr] = true;
                q.push(*itr);
            }
        }
    }
}