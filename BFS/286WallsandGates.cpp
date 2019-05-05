/**
 Solution:
 we initiate breadth-first search (BFS) from all gates at the same time. Since BFS guarantees that we search all rooms of distance d before searching rooms of distance d + 1, the distance to an empty room must be the shortest.
*/
class Solution {
private:
    vector<vector<int>> DIRECTIONS = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if(m==0) return;
        int n = rooms[0].size();
        queue<vector<int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(rooms[i][j]==0){
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            vector<int> point = q.front();
            q.pop();
            int i = point[0];
            int j = point[1];
            for(auto d:DIRECTIONS){
                int r = i + d[0];
                int c = j + d[1];
                if(r<0 || c<0 || r>=m || c>=n || rooms[r][c]!=INT_MAX) continue;
                rooms[r][c] = rooms[i][j]+1;
                q.push({r,c});
            }
        }
    }
};