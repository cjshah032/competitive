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

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
    cin.ignore();
    char n;
	cin>>n;
    char old_n = '\0';
    
	for(int i=0;i<t;i++)  //solving test cases and finding result for each
	{
	    if(old_n != '\0'){
	        n = old_n;
	    }
	    
	    set<int> graph[(int)(n-'A')+1]; 
	    bool visited[(int)(n-'A')+1] = {false};
	    string edge;
	    
	    while(cin>>edge){
	        if(edge.size() == 1)
	        {
	            old_n = edge[0];
	            break;
	        }
	        graph[(int)(edge[0]-'A')].insert((int)(edge[1]-'A'));
	        graph[(int)(edge[1]-'A')].insert((int)(edge[0]-'A'));
	    }
	    cin.ignore();
	    
	    int count = 0;
	    
	    for(int j=0; j<(int)(n-'A')+1; j++)
	    {
	        if(visited[j] == true)
	        continue;
	        else{
	            count++;
	            dfs(j, graph, visited);
	        }
	    }
	    
	    cout<<count<<endl;
	}
	return 0;
}
