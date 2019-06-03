class Solution {
private:
    vector<vector<int>> DIRECTIONS = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = m == 0 ? 0 : rooms[0].size();
        queue<vector<int>> q; 
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(rooms[i][j] == 0) q.push({i,j});
        while(!q.empty()){
            vector<int> tmp = q.front(); q.pop();
            int i = tmp[0], j = tmp[1];
            for(auto d:DIRECTIONS){
                int r = i + d[0], c = j + d[1];
                if(r>=0 && c>=0 && r<m && c<n && rooms[r][c]==INT_MAX){
                    rooms[r][c] = rooms[i][j] + 1;
                    q.push({r,c});
                }
            }
        }
    }
};