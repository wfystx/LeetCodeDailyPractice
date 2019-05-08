class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
        int r,c,count;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                count = 0;
                for(auto d:dir){
                    r = i+d[0];
                    c = j+d[1];
                    if(r>=0 && c>=0 && r<board.size() && c<board[0].size() && board[r][c]&1==1){
                        count++;
                    }
                }
                if(board[i][j]==1 && 2<=count && count<=3) board[i][j] |= 2;
                else if(board[i][j]==0 && count==3) board[i][j] |= 2;
            }
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                board[i][j] >>= 1;
            }
        }
    }
};