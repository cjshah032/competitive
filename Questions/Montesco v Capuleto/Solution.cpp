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
	int t;
	cin>>t;
    
	for(int i=0;i<t;i++)  //solving test cases and finding result for each
	{
	    cin.ignore();
	    int n; 
	    cin>>n;
	    set<int> graph[n];
	    for(int j=0; j<n; j++)
	    {
	        int e; 
	        cin>>e;
	        int enemy;
	        for(int k =0; k<e; k++)
	        {
	            cin>>enemy;
	            if(enemy > n)
	            continue;
	            graph[j].insert(enemy-1);
	            graph[enemy-1].insert(j);
	        }
	    }
	    
	    bool visited[n];
	    for(int j=0; j<n; j++)
	        visited[j] = false;
	        
	   
	    int max_count = 0;
	    for(int j=0; j<n; j++)
	    {
	        if(visited[j] == true)
	        continue;
	        
	        else{
	            int color_count[] = {0, 0};
                vector<int> color(n, -1);
                queue<int> q; q.push(j);
                color[j] = 0;
                color_count[0]++;
                bool check = true;
                while(!q.empty() && check==true){
                    int u = q.front(); q.pop();
                    for(auto itr = graph[u].begin(); itr != graph[u].end(); ++itr)
                    {
                        if(color[*itr] == -1)
                        {
                            visited[*itr] = true;
                            color[*itr] = 1 - color[u];
                            color_count[color[*itr]]++;
                            q.push(*itr);
                        }
                        
                        else if(color[*itr] == color[u])
                        {
                            check = false;
                            break;
                        }
                    }
                }
	            if(check == true)
	            max_count += max(color_count[0], color_count[1]);
	        }
	    }
	    cout<<max_count<<endl;
	}
	return 0;
}
