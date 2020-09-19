//graph = adjacency list of graph
//visited = boolean array 
//v = no. of vertices
//ts = vector to store topsort order. Should be read backwards.
void dfs_mod (int dnode, set<int> graph[], bool visited[], vi &ts){ //mod to imply modified dfs
    visited[dnode] = true;
    for(auto itr = graph[dnode].begin(); itr != graph[dnode].end(); ++itr)
    {
        if(visited[*itr] == true)
        continue;
        else{
            visited[*itr] = true;
            dfs_mod(*itr, graph, visited, ts);
        }
    }
    ts.push_back(dnode);
}


//to be used in main:
for(int l = 0; l < v; l++)
{
    if(visited[l] == true)
        continue;
        
    else{
        dfs_mod(l, graph, visited, ts);
    }
}

//Displaying topsort order:
for(auto itr = ts.rbegin(); itr != ts.rend(); ++itr)
    cout<<*itr;
