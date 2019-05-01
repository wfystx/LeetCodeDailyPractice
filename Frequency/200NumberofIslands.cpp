/**
 Solution:
 Use depth first search to traverse every node in the grid.
 Be careful about the boundary.
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int x = grid.size();
        if(x==0) return 0;
        int y = grid[0].size();
        if(y==0) return 0;
        int count = 0;
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int i, int j){
        int x = grid.size();
        int y = grid[0].size();
        while(i<x && i>=0 && j<y && j>=0 && grid[i][j]=='1'){
            grid[i][j] = '0';
            dfs(grid, i, j+1);            
            dfs(grid, i, j-1);
            dfs(grid, i+1, j);
            dfs(grid, i-1, j);
        }
    }
};