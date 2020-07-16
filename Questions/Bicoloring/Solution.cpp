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

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    while(true){
        int n, e;
        cin>>n;
        if(n == 0)
            break;
        cin>>e;
        
        set<int> graph[n];
            
        for(int i=0; i<e; i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].insert(b);
            graph[b].insert(a);
        }
        
        bool bipartite = true;
        vector<int> color(n, -1);
        queue<int> q; q.push(0);
        color[0] = 0;
        
        while(!q.empty() && bipartite == true){
            int u = q.front(); q.pop();
            for(auto itr = graph[u].begin(); itr != graph[u].end(); ++itr)
            {
                if(color[*itr] == -1)
                {
                    color[*itr] = 1 - color[u];
                    q.push(*itr);
                }
                
                else{
                    if(color[*itr] == color[u])
                    {
                        bipartite = false;
                        break;
                    }
                }
            }
        }
        if(bipartite)
        cout<<"BICOLORABLE."<<endl;
        else cout<<"NOT BICOLORABLE."<<endl;
    }
	return 0;
}
