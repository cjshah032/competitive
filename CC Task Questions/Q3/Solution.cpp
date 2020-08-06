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

void dfs_mod(int s, vector<int> *AdjList, int *parent, bool *visited)  //s = source node
{
    visited[s] = true;
    for(auto itr = AdjList[s].begin(); itr != AdjList[s].end(); ++itr)
    {
        if(visited[*itr] == true && *itr != parent[s])
        {
            cout<<*itr<<" "<<s<<endl;
            exit(0);
        }
        
        else if(*itr == parent[s])
        continue;
        
        else {
            parent[*itr] = s;
            dfs_mod(*itr, AdjList, parent, visited);
        }
    }
}

void FindExtraEdge(vector<int> *AdjList, int n)
{
    int parent[n];
    bool visited[n];
    for (int i=0; i<n; i++)
    {
        parent[i] = -1;
        visited[i] = false;
    }
    dfs_mod(0, AdjList, parent, visited);
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> AdjList[n];
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        AdjList[a].pb(b);
        AdjList[b].pb(a);
    }
    FindExtraEdge(AdjList, n);
	return 0;
}
