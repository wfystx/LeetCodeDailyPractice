class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r[9][9] = {0}, c[9][9] = {0}, k[9][9] = {0};
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if((board[i][j]!='.')){
                    int n = board[i][j] - '0' - 1;
                    if(r[i][n] || c[j][n] || k[i/3*3+j/3][n]) return false;
                    r[i][n] = c[j][n] = k[i/3*3+j/3][n] = 1;
                }
            }
        }
        return true;
    }
};