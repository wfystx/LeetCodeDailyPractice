/**
 Solution:
 BFS method
*/
class Solution {
private:
    vector<vector<int>> next = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int x = grid.size();
        if(x==0) return 0;
        int y = grid[0].size();
        if(y==0) return 0;
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                if(grid[i][j]=='1'){
                    grid[i][j]=='0';
                    count ++;
                    queue<vector<int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        vector<int> temp = q.front(); q.pop();
                        for(int k=0; k<4; i++){
                            int r = temp[0] + next[k][0];
                            int c = temp[1] + next[k][1];
                            if(r>=0 && c>=0 && r<x && c<y && grid[r][c]=='1'){
                                grid[r][c] = '0';
                                q.push({r,c});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};