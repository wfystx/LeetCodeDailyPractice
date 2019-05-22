class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n,'.'));
        helper(res, board, 0, n);
        return res;
    }
    void helper(vector<vector<string>>& res, vector<string>& board, int row, int n){
        if(row==n){
            res.emplace_back(board);
            return;
        }
        for(int i=0; i<n; i++){
            if(check(board, row, i)){
                board[row][i] = 'Q';
                helper(res, board, row+1, n);
                board[row][i] = '.';
            }
        }
    }
        
    bool check(vector<string>& board, int row, int col){
        for(int i=0; i<row; i++) if(board[i][col] == 'Q') return false;
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) if(board[i][j] == 'Q') return false;
        for(int i=row-1, j=col+1; i>=0 && j<board.size(); i--, j++) if(board[i][j] == 'Q') return false;
        return true;
    }
};