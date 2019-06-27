class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> s = heights;
        sort(s.begin(), s.end());
        int res = 0;
        for(int i = 0; i < s.size(); i++) res += heights[i] != s[i];
        return res;
    }
};