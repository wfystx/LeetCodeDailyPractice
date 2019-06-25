class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = m == 0 ? 0 : grid[0].size();
        int res = 0;
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int cnt = helper(grid, i + 1, j) + helper(grid, i - 1, j) + helper(grid, i, j + 1) + helper(grid, i, j - 1);
                    cnt = 4 - cnt;
                    res += cnt;
                }
            }
        }
        return res;
    }
    int helper(vector<vector<int>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size(), cnt = 0;
        if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1) cnt++;
        return cnt;
    }
};