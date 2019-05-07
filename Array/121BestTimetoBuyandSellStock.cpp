/** 
 Solution:
 One pase
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int profit = 0, m = INT_MAX;
        for(int i=0; i<prices.size(); i++){
            if(prices[i]<m) m = prices[i];
            else profit = max(profit, prices[i]-m);
        }
        return profit;
    }
};