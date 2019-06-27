class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> res(N, 0);
        vector<vector<int>> g(N);
        for(auto p:paths){
            g[p[0] - 1].push_back(p[1] - 1);
            g[p[1] - 1].push_back(p[0] - 1);
        }
        for(int i = 0; i < N; i++){
            vector<int> color(5, 0);
            for(auto j:g[i]) color[res[j]] = 1;
            for(int c = 4; c > 0; c--)
                if(!color[c]) res[i] = c;
        }
        return res;
    }
};