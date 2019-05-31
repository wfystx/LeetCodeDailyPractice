class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int> dp(n);
        dp[0] = 1;
        int u2 = 0, u3 = 0, u5 = 0;
        for(int i=1; i<n; i++){
            dp[i] = min(min(dp[u2]*2, dp[u3]*3), dp[u5]*5);
            if(dp[i] == dp[u2]*2) u2++;
            if(dp[i] == dp[u3]*3) u3++;
            if(dp[i] == dp[u5]*5) u5++;
        }
        return dp[n-1];
    }
};