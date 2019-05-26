class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n, cnt = 0;
        if(m == 0 || (n = grid[0].size()) == 0) return 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == '1'){ cnt ++; dfs(grid, i, j);}
        return cnt;
    }
    void dfs(vector<vector<char>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        while(i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == '1'){
            grid[i][j] = '#';
            dfs(grid, i + 1, j);
            dfs(grid, i - 1, j);
            dfs(grid, i, j + 1);
            dfs(grid, i, j - 1);
        }
    }
};