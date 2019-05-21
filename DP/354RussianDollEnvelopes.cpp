class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmpfunc);
        if(!envelopes.size()) return 0;
        int res = 1;
        vector<int> dp(envelopes.size(),0);
        dp[0] = 1;
        for(int i=1; i<envelopes.size(); i++){
            for(int j=0; j<i; j++){
                if(envelopes[j][0]<envelopes[i][0] && envelopes[j][1]<envelopes[i][1])
                    dp[i] = max(dp[i],dp[j]);
            }
            dp[i]++;
            res = max(res, dp[i]);
        }
        return res;
    }
private:
    struct cmp { 
        bool operator()(vector<int> a, vector<int> b) { 
            return a[0]*a[1] < b[0]*b[1];
        } 
    }cmpfunc;
};