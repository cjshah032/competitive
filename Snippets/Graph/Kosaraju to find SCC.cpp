//first implementation of dfs
void dfs1(set<int> graph[], int dnode, stack<int> &stck, bool visited[]){
    visited[dnode] = true;
    
    for(auto itr = graph[dnode].begin(); itr != graph[dnode].end(); ++itr)
    {
        int u = *itr;
        if(visited[u] != true)
        dfs1(graph, u, stck, visited);
    }
    
    stck.push(dnode);
}

//second implementation of dfs
void dfs2(set<int> graph[], int dnode, bool visited[]){
    visited[dnode] = true;
    cout<<dnode<<" ";
    
    for(auto itr = graph[dnode].begin(); itr != graph[dnode].end(); ++itr)
    {
        int u = *itr;
        if(visited[u] != true)
        dfs2(graph, u, visited);
    }
}

void KosarajuSCC(set<int> graph[], set<int> trans_graph[],int n){
    bool visited[n] = {false};
    stack<int> stck;
    
    //making the stack (finishing time)
    for(int i=0; i<n; i++)
    {
        if(visited[i] == true)
        continue;
        else dfs1(graph, i, stck, visited);
    }
    
    //reinitialize visited for second dfs
    for(int i=0; i<n; i++)
    visited[i] = false;

    //running dfs on transpose of the graph    
    while(!stck.empty())
    {
        int u = stck.top();
        stck.pop();
        if(visited[u] == false)
        {
            dfs2(trans_graph, u, visited);
            cout<<endl;
        }
    }
}
