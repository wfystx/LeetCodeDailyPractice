class Solution {
public:
    vector<vector<int>> DIR{{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 1;
        int cnt = 1, n = grid.size() - 1;
        if(grid[0][0] == 1 || grid[n][n] == 1) return -1;
        queue<vector<int>> q;
        q.push({0, 0});
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                vector<int> tmp = q.front(); q.pop();
                if(tmp[0] == n && tmp[1] == n) return cnt;
                for(auto d:DIR){
                    int r = tmp[0] + d[0], c = tmp[1] + d[1];
                    if(r >= 0 && r <= n && c >= 0 && c <= n && grid[r][c] == 0){
                        q.push({r,c});
                        grid[r][c] = 1;
                    } 
                }
            }
            cnt++;
        }
        return -1;
    }
};