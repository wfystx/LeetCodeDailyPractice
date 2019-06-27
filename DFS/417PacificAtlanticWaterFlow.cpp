class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
        vector<vector<bool>> p(m, vector<bool>(n, false)), a(m, vector<bool>(n, false));
        vector<vector<int>> res;
        for(int i = 0; i < m; i++){
            dfs(matrix, i, 0, p);
            dfs(matrix, i, n - 1, a);
        }
        for(int i = 0; i < n; i++){
            dfs(matrix, 0, i, p);
            dfs(matrix, m - 1, i, a);
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(p[i][j] && a[i][j]) res.push_back({i,j});
        return res;
    }
    void dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<bool>>& visited){
        int m = matrix.size(), n = matrix[0].size();
        visited[i][j] = true;
        for(auto d:dirs){
            int r = i + d[0], c = j + d[1];
            if(r >= 0 && c >= 0 && r < m && c < n && matrix[r][c] >= matrix[i][j] && !visited[r][c])
                dfs(matrix, r, c, visited);
        }
    }
};