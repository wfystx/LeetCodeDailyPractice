class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n;
        if(m == 0 || (n = board[0].size()) == 0) return;
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][n-1] == 'O') dfs(board, i, n-1);
        }
        for(int j=1; j<n-1; j++){
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[m-1][j] == 'O') dfs(board, m-1, j);
        }
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(board[i][j] == 'O') board[i][j] = 'X';
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(board[i][j] == '#') board[i][j] = 'O';        
    }
    void dfs(vector<vector<char>>& board, int i, int j){
        int m = board.size(), n = board[0].size();
        while(i>=0 && j>=0 && i<m && j<n && board[i][j] == 'O'){
            board[i][j] = '#';
            dfs(board, i+1, j);
            dfs(board, i-1, j);
            dfs(board, i, j+1);
            dfs(board, i, j-1);
        }
    }
};