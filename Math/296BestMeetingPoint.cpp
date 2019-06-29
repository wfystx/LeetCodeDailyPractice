class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = m == 0 ? 0 : grid[0].size();
        vector<int> row, col;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1){
                    row.push_back(i);
                    col.push_back(j);
                }
        int res = 0;
        sort(col.begin(), col.end());
        int m1 = row[row.size() / 2], m2 = col[col.size() / 2];
        for(int i:row) res += abs(i - m1);
        for(int j:col) res += abs(j - m2);
        return res;
    }
};