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

//traversal system: S, SE, E, NE, N, NW, W, SW 
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; 

//it is assumed that grid is declared globally
int floodfill(int r, int c, char c1, char c2)   //c1 is traversable area 
{                                               //and c2 is obstacle 
    if(r<0 || c<0 || r>=R || c>=C)              //R,C are dimensions of grid
    return 0;
    else if (grid[r][c] == c2) return 0;
    int connected_area = 0;
    
    for(int d = 0; d < 8; d++)
    {
        connected_area += floodfill(r+dr[d], c+dr[d], c1, c2, grid, R, C);
    }
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
    cin.ignore();
    
	for(int i=0;i<t;i++)  //solving test cases and finding result for each
	{
	    char *row;
	    cin>>row;
	    char **grid;
	    int k = 1;
	    for(int j=0; j<(sizeof(row)/sizeof(char)); j++)
	        grid[0][j] = row[j];
	    
	    int r, c;
	    while (true)
	    {
	        cin>>row;
	        if(row[0] != 'L' || row[0] != 'W')
	        {
	            r = atoi(row);
	            break;
	        }
	        for(int j=0; j<(sizeof(row)/sizeof(char)); j++)
	            grid[k][j] = row[j];
	        k++;
	    }
	    cin>>c;
	    cout<<floodfill(r-1, c-1, 'W', 'L', grid, k, (sizeof(grid[0])/sizeof(char)))
	    while(cin>>r){
	        cin>>c;
	        cout<<floodfill(r-1, c-1, 'W', 'L', grid, k, (sizeof(grid[0])/sizeof(char)));
	    }
	    cout<<endl;
	}
	return 0;
}
