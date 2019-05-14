class Solution {
private:
    bool result;
public:
    bool exist(vector<vector<char>>& board, string word) {
        result = false;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    if(helper(board, i, j, word, 0)) return true;
                }
            }
        }
        return result;
    }
    bool helper(vector<vector<char>>& board, int x, int y, string word, int index){
        if(x>=0 && y>=0 && x<board.size() && y<board[0].size() && board[x][y]==word[index]){
            if(index==word.size()-1) return true;
            char c = board[x][y];
            board[x][y] = '#';
            bool b = helper(board, x+1, y, word, index+1) || helper(board, x-1, y, word, index+1) || helper(board, x, y+1, word, index+1) || helper(board, x, y-1, word, index+1);
            board[x][y] = c;
            return b;
        }else return false;
    }
};