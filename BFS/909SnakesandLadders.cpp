class Solution {
public:
    vector<int> calc(int nxt, int n){
        int x = (nxt - 1) / n;
        int y = (nxt - 1) % n;
        if(x % 2 == 1) {
            y = n - 1 - y;
        }
        x = n - 1 - x;
        return {x,y};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        queue<int> q;
        int step = 0;
        q.push(1);
        while(!q.empty()){
            int sz = q.size();
            for(int k=0; k<sz; k++){
                int cur = q.front(); q.pop();
                if(cur == n*n) return step;
                for(int i=1; i<=6; i++){
                    int nxt = cur + i;
                    if(nxt > n*n) break;
                    vector<int> tmp = calc(nxt, n);
                    int x = tmp[0], y = tmp[1];
                    //cout << x << "-" << y << endl;
                    if(board[x][y] != -1){
                        nxt = board[x][y];
                        tmp = calc(nxt, n);
                        x = tmp[0];
                        y = tmp[1];
                    } 
                    if(visited[x][y] == true) continue;
                    visited[x][y] = true;
                    q.push(nxt);
                }
            }
            
            step ++;
        }
        return -1;
    }
};