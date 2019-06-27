class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size(), res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                res = max(res, dfs(matrix, i, j, dp));
        return res;
    }
    
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        int m = matrix.size(), n = matrix[0].size();
        if(dp[i][j]) return dp[i][j];
        for(auto d:dirs){
            int r = i + d[0], c = j + d[1];
            if(r < 0 || r >= m || c < 0 || c >= n || matrix[r][c] <= matrix[i][j]) continue;
            dp[i][j] = max(dp[i][j], dfs(matrix, r, c, dp));
        }
        return ++dp[i][j];
    }
};