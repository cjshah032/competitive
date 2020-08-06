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
#define mp make_pair

class DisjointSet{
    public:
        int subsets;
        vector<int> parent;
        DisjointSet(int n){
            for (int i=0; i<n; i++)
            {
                parent.push_back(-1);
            }
            subsets = n;
        }
        
        int Find(int a){        //finds the representative of a's set
            if (parent[a] == -1){
                return a;
            }
            
            else{
                int result = Find(parent[a]);
                parent[a] = result;
                return result;
            }
        }
        
        void JoinSet(int a, int b){     //joins the set of a to set of b
            int a_rep = Find(a);
            int b_rep = Find(b);
            parent[a_rep] = b_rep;
            subsets --;
        }
        
        bool IsSameSet(int a, int b){
            if(Find(a) == Find(b))
            return true;
            else return false;
        }
};

float MiniMaxDist (vector<pair<int, int>> points, int n, int k){     //n = number of points, k=no of required subsets
    vector<pair<float, pair<int, int>>> dists;  //distance from points[i] to points[j]
    
    for(int i=0; i<points.size(); i++)
    {
        for(int j=i+1; j<points.size(); j++)
        {
            float dist;
            dist = (float)sqrt(((points[i].first - points[j].first)*(points[i].first - points[j].first)) + ((points[i].second - points[j].second)*(points[i].second - points[j].second)));
            dists.pb(mp(dist, mp(i, j)));
        }
    }
    sort(dists.begin(), dists.end());
    DisjointSet ds(n);
    while(ds.subsets != k)
    {
        auto itr = dists.begin();
        if(!ds.IsSameSet((*itr).second.first, (*itr).second.second))
            ds.JoinSet((*itr).second.first, (*itr).second.second);
        dists.erase(itr);
    }
    
    bool flag = true;
    while(flag == true){
         auto itr = dists.begin();
        if(!ds.IsSameSet((*itr).second.first, (*itr).second.second))
        {
            flag = false;
            break;
        }
        dists.erase(itr);
    }
    auto itr = dists.begin();
    return (*itr).first;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n>>k;
    vector<pair<int, int>> points;
	for(int i=0; i<n; i++)
	{
		int a,b;
		points.pb(mp(a, b));
	}
    float result = MiniMaxDist(points, n, k);
    cout<<result;
	return 0;
}
