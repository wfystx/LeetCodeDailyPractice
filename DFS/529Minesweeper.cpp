class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        helper(board, click[0], click[1]);
        return board;
    }
    
    bool check(vector<vector<char>>& board, int x, int y){
        return x>=0 && x<board.size() && y>=0 && y<board[0].size();
    }
    
    void helper(vector<vector<char>>& board, int x, int y){
        if(!check(board, x, y)) return;
        if(board[x][y] == 'E'){
            int cnt = 0;
            if(check(board, x + 1, y) && board[x + 1][y] == 'M') cnt++;
            if(check(board, x - 1, y) && board[x - 1][y] == 'M') cnt++;
            if(check(board, x, y + 1) && board[x][y + 1] == 'M') cnt++;
            if(check(board, x, y - 1) && board[x][y - 1] == 'M') cnt++;
            if(check(board, x + 1, y + 1) && board[x + 1][y + 1] == 'M') cnt++;
            if(check(board, x + 1, y - 1) && board[x + 1][y - 1] == 'M') cnt++;
            if(check(board, x - 1, y + 1) && board[x - 1][y + 1] == 'M') cnt++;
            if(check(board, x - 1, y - 1) && board[x - 1][y - 1] == 'M') cnt++;
            
            if(cnt > 0) board[x][y] = '0' + cnt;
            else{
                board[x][y] = 'B';
                helper(board, x + 1, y);
                helper(board, x - 1, y);
                helper(board, x, y + 1);
                helper(board, x, y - 1);
                helper(board, x + 1, y + 1);
                helper(board, x + 1, y - 1);
                helper(board, x - 1, y + 1);
                helper(board, x - 1, y - 1);
            }
        }
    }
};