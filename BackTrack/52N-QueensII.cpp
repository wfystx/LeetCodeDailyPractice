class Solution {
public:
    int cnt = 0;
    int totalNQueens(int n){
        vector<bool> cols(n, false);
        vector<bool> d1(2*n, false);
        vector<bool> d2(2*n, false);
        helper(0, cols, d1, d2, n);
        return cnt;
    }
    void helper(int row, vector<bool>& cols, vector<bool>& d1, vector<bool>& d2, int n){
        if(row == n) cnt ++;
        for(int col=0; col<n; col++){
            int id1 = col - row + n;
            int id2 = col + row;
            if(cols[col] || d1[id1] || d2[id2]) continue;
            cols[col] = true; d1[id1] = true; d2[id2] = true;
            helper(row+1, cols, d1, d2, n);
            cols[col] = false; d1[id1] = false; d2[id2] = false;
        }
    }
    /*
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int cnt = 0;
        helper(board, 0, n, cnt);
        return cnt;
    }
    void helper(vector<string>& board, int row, int n, int& cnt){
        if(row == n) {
            cnt++;
            return;
        }
        for(int col=0; col<n; col++){
            if(check(board, row, col, n)){
                board[row][col] = 'Q';
                helper(board, row+1, n, cnt);
                board[row][col] = '.';
            }
        }
    }
    bool check(vector<string> board, int row, int col, int n){
        for(int i=0; i<row; i++) if(board[i][col] == 'Q') return false;
        for(int i=row-1, j=col-1; i>=0&&j>=0; i--, j--) if(board[i][j] == 'Q') return false;
        for(int i=row-1, j=col+1; i>=0&&j<n; i--, j++) if(board[i][j] == 'Q') return false;
        return true;
    }
    */
};