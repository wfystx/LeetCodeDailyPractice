class Solution {
public:
    int longestRepeatingSubstring(string S) {
        int n = S.size(), res = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < n; i++) for(int j = 0; j < i; j++)
            if(S[i] == S[j]) res = max(res, dp[i + 1][j + 1] = dp[i][j] + 1);
        return res;
    }
};