class Solution {
private:
    char E = '.';
    vector<char> nums = {'1','2','3','4','5','6','7','8','9'};
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
    bool helper(vector<vector<char>>& board, int row, int col){
        if(col == 9){
            col = 0; 
            row++;
        }
        if(row == 9) return true;
        if(board[row][col]!=E) return helper(board, row, col+1);
        for(char c:nums){
            if(check(board, row, col, c)){
                board[row][col] = c;
                if(helper(board, row, col+1)) return true;
            }
        }
        board[row][col] = E;
        return false;
    }
    bool check(vector<vector<char>>& board, int row, int col, char c){
        for(auto r:board) if(r[col] == c) return false;
        for(auto cc:board[row]) if(cc == c) return false;
        int brow = row/3*3, bcol = col/3*3;
        for(int i=0; i<3; i++) for(int j=0; j<3; j++) if(c == board[brow+i][bcol+j]) return false;
        return true;
    }
};