class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int> m;
        int cnt = 0;
        for(auto d:dominoes) cnt += m[min(d[0], d[1]) * 10 + max(d[0], d[1])]++;
        return cnt;
    }
};