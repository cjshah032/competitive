void dfs (int dnode, set<int> *graph, bool *visited){
    visited[dnode] = true;
    for(auto itr = graph[dnode].begin(); itr != graph[dnode].end(); ++itr)
    {
        if(visited[*itr] == true)
        continue;
        else{
            visited[*itr] = true;
            dfs(*itr, graph, visited);
        }
    }
}
