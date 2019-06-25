class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i = 1; i < 10; i++)
            dfs(n, res, i);
        return res;
    }
    void dfs(int n, vector<int>& res, int cur){
        if(cur > n) return;
        res.push_back(cur);
        for(int i = 0; i < 10; i++){
            if(cur * 10 + i > n) return;
            dfs(n, res, cur * 10 + i);
        }
    }
};