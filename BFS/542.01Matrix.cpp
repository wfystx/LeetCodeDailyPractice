class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return matrix;
        queue<pair<int, int>> q;
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<vector<int>> rev(matrix.size(), vector<int>(matrix[0].size(),INT_MAX));
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    rev[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int, int> temp = q.front();q.pop();
            for(int i=0; i<4; i++){
                int r = temp.first+dir[i][0];
                int c = temp.second+dir[i][1];
                if(r>=0 && c>=0 && r<matrix.size() && c<matrix[0].size()){
                    if(rev[r][c]>rev[temp.first][temp.second]+1){
                        rev[r][c] = rev[temp.first][temp.second]+1;
                        q.push({r,c});
                    }
                }
            }
        }
        return rev;
    }
};