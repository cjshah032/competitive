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
bool dfs_mod (int dnode, set<int> *graph, bool *visited, vector<int> *ts, vi *stck)
{
    (*stck).push_back(dnode);
    visited[dnode] = true;
    //cout<<graph[dnode].size()<<endl;
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
	int t;
	cin>>t;
    string curr, prev;
    cin>>curr;
    set<int> graph[26];
    bool *visited = new bool[26];
    for(int i=0; i<26; i++)
        visited[i] = false;
        
	for(int i=0; i<t-1; i++)  //solving test cases and finding result for each
	{
	    prev = curr;
	    cin>>curr;
	    //cout<<curr<<prev;
        bool alaghe = false;
	    for(int j=0; j<(min(prev.size(), curr.size())); j++)
	    {
	        if(prev[j] != curr[j])
	       {
	           //cout<<"here"<<(int)(curr[j] - 'a');
	           graph[(int)(prev[j] - 'a')].insert((int)(curr[j] - 'a'));
	           alaghe = true;
	           //cout<<graph[(int)(prev[j] - 'a')].size();
	           break;
	       }
	    }
	    
	    if(alaghe == false && prev.size() > curr.size())
	    {
	        cout<<"Impossible";
	        return 0;
	    }
	}
	
	vector<int> ts;
	bool cycle = false;
	for(int l = 25; l >= 0; l--)
        {
            if(visited[l] == true)
                continue;
                
            else{
                vector<int> stck;
                //cout<<l;
                if(dfs_mod(l, graph, visited, &ts, &stck)==false)
                {
                    cout<<"Impossible"<<endl;
                    cycle = true;
                    break;
                }
            }
        }
        
    if(cycle) return 0;
    
    for(auto itr = ts.rbegin(); itr != ts.rend(); ++itr)
        cout<<(char)(*itr+'a');
	
	return 0;
}