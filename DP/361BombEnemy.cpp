class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int i, j, row, col, head, tail, res=0;
        row = grid.size();
        if(!row) return 0;
        col = grid[0].size();
        if(!col) return 0;
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for(i=0; i<row; i++){
            for(j=head=tail=0; j<col; j++){
                dp[i][j] = grid[i][j]!='0' ? 0:(dp[i][j]+head);
                dp[i][col-j-1] = grid[i][col-j-1]!='0' ? 0:(dp[i][col-j-1]+tail);
                head = grid[i][j]=='W' ? 0:(head+(grid[i][j]=='E' ? 1:0));
                tail = grid[i][col-j-1]=='W' ? 0:(tail+(grid[i][col-j-1]=='E' ? 1:0));
            }
        }
        for(j=0; j<col; j++){
            for(i=head=tail=0; i<row; i++){
                dp[i][j] = grid[i][j]!='0' ? 0:(dp[i][j]+head);
                dp[row-i-1][j] = grid[row-i-1][j]!='0' ? 0:(dp[row-i-1][j]+tail);
                head = grid[i][j]=='W' ? 0:(head+(grid[i][j]=='E' ? 1:0));
                tail = grid[row-i-1][j]=='W' ? 0:(tail+(grid[row-i-1][j]=='E' ? 1:0));
            }
        }
        for(i=0; i<row; i++){
            for(j=0; j<col; j++){
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};