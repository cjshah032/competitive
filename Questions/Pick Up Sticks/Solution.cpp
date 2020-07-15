#include <bits/stdc++.h> 
using namespace std; 
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll unsigned long long
#define pb push_back
#define ppb pop_back
#define endl '\n'
#define vi  vector<int>
#define vii vector<pair<int, int>>
#define vs  vector<string>
#define qi queue<int>
#define MAX 1000000000000000007

//also checks cycles. true = no cycle
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

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	while(true)  //solving test cases and finding result for each
	{
	    int n, m;
	    cin>>n>>m;
	    if (n == 0 && m == 0)
	        break;
	    set<int> *graph = new set<int>[n];
	    bool *visited = new bool[n];
	    int a, b; vector<int> ts;
	    
	    for (int i=0; i<m; i++)
	    {
	        cin>>a>>b;
	        graph[a-1].insert(b-1);
	    }
	    
	    bool cycle = false;
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
        
        if(cycle) continue;
        for(auto itr = ts.rbegin(); itr != ts.rend(); ++itr)
            cout<<*itr+1<<endl;
	}
	return 0;
}
