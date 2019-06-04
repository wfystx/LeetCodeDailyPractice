class TicTacToe {
private:
    vector<int> rows;
    vector<int> cols;
    int diagonal, anti_diagonal;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows.resize(n,0); cols.resize(n,0);
        diagonal = 0; anti_diagonal = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int nxt = player == 1 ? 1 : -1;
        int size = rows.size();
        rows[row] += nxt;
        cols[col] += nxt;
        if(row == col) diagonal += nxt;
        if(row + col == size - 1) anti_diagonal += nxt;
        if(abs(rows[row]) == size || abs(cols[col]) == size || abs(diagonal) == size || abs(anti_diagonal) == size) return player;
        return 0; 
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */