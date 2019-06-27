class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> m;
        for(auto x:matrix){
            string s;
            int top = x[0];
            for(auto i:x) s += i == top ? 1 : 0;
            m[s] ++;
        }
        int res = 0;
        for(auto item:m) res = max(res, item.second);
        return res;
    }
};