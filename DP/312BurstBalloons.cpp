class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> mynums(1,1);
        for(auto n:nums) if(n > 0) mynums.push_back(n);
        mynums.push_back(1);
        
        int n = mynums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int k = 2; k < n; k++){
            for(int left = 0; left < n - k; left++){
                int right = left + k;
                for(int i = left + 1; i < right; i++){
                    dp[left][right] = max(dp[left][right], 
                            mynums[left] * mynums[i] * mynums[right] + dp[left][i] + dp[i][right]);
                }
            }
        }
        return dp[0].back();
    }
};