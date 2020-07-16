//Creates TOPSORT order and also checks for cycles.

//Note: graph - Adjacency List, visited = array to store if node is visited
//ts = vector to store the TopSort order, stck = Stack implemented in vector to check for cycles.


//Modified DFS:
bool dfs_mod (int dnode, set<int> *graph, bool *visited, vector<int> *ts, vi *stck){
    (*stck).push_back(dnode);
    visited[dnode] = true;
    for(auto itr = graph[dnode].begin(); itr != graph[dnode].end(); ++itr)
    {
        if(visited[*itr] == true)
        {
            if ((*stck).size() != 0)
            {   
                if (find((*stck).begin(), (*stck).end(), *itr) != (*stck).end())
                {   
                    return false;
                }
            }
            continue;
        }
        else{
            visited[*itr] = true;
            bool flag = dfs_mod(*itr, graph, visited, ts, stck);
            if(flag == false)
            {   
                return false;
            }
        }
    }
    (*ts).push_back(dnode);
    (*stck).erase(--(*stck).end());
    return true;
}

//For Loop: (cycle = boolean to store if cycle is present, n = no of nodes)
for(int l = 0; l < n; l++)
       {
           if(visited[l] == true)
               continue;
               
           else{
               vector<int> stck;
               if(dfs_mod(l, graph, visited, &ts, &stck)==false)
               {
                   cout<<"IMPOSSIBLE"<<endl;
                   cycle = true;
                   break;
               }
           }
       }

//Printing TOPSORT:
for(auto itr = ts.rbegin(); itr != ts.rend(); ++itr)
    cout<<*itr+1<<endl;