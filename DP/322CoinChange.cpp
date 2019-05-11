/**
 Solution:
 Build a vector for dp. Initial it with INT_MAX, and set dp[0] as 0;
 So if we can find that there is a non INT_MAX value in dp[i-coins[j]] it means we can reach this value.
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int m = amount+1;
        vector<int> dp(m,m);
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(int j=0; j<coins.size(); j++){
                if(coins[j]<=i){
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};