class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = m == 0 ? 0 : grid[0].size();
        int res = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1){
                    int sum = 0;
                    dfs(grid, i, j, sum);
                    res = max(res, sum);
                }
        return res;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int& sum){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return;
        sum ++;
        grid[i][j] = 0;
        dfs(grid, i + 1, j, sum);
        dfs(grid, i - 1, j, sum);
        dfs(grid, i, j + 1, sum);
        dfs(grid, i, j - 1, sum);
    }
};