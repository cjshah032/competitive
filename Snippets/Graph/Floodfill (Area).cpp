//it is assumed that grid is declared globally
int floodfill(int r, int c, char c1, char c2)   //c1 is traversable area 
{                                               //and c2 is obstacle 
    if(r<0 || c<0 || r>=R || c>=C)              //R,C are dimensions of grid
    return 0;
    else if (grid[r][c] == c2) return 0;
    int connected_area = 0;
    
    for(int d = 0; d < 8; d++)
    {
        connected_area += floodfill(r+dr[d], c+dr[d], c1, c2);
    }
}