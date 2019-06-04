class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = m == 0 ? 0 : forest[0].size();
        vector<vector<int>> trees;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(forest[i][j] > 1) trees.push_back({forest[i][j], i, j});
        sort(trees.begin(), trees.end());
        int res = 0;
        for(int i=0, cur_r=0, cur_c=0; i<trees.size(); i++){
            int step = bfs(forest, cur_r, cur_c, trees[i][1], trees[i][2]);
            if(step == -1) return -1;
            res += step;
            cur_r = trees[i][1]; cur_c = trees[i][2];
        }
        return res;
    }
    int bfs(vector<vector<int>>& forest, int sr, int sc, int er, int ec){
        if(sr == er && sc == ec) return 0;
        int m = forest.size(), n = forest[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        visited[sr][sc] = true;
        q.push({sr,sc});
        int step = 0;
        while(!q.empty()){
            step++;
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int row = q.front().first, col = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int r = row + dir[i], c = col + dir[i+1];
                    if(r<0 || c<0 || r>=m || c>=n || visited[r][c] || forest[r][c]==0) continue;
                    if(r == er && c == ec) return step;
                    visited[r][c] = true;
                    q.push({r,c});
                }
            }
        }
        return -1;
    }
};