class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle.back());
        for(int layer = n - 2; layer >= 0; layer--)
            for(int i = 0; i <= layer; i++)
                dp[i] = min(dp[i], dp[i + 1]) + triangle[layer][i];
        return dp[0];
    }
};