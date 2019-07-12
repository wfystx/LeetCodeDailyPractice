class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;
        if(prices.empty()) return 0;
        for (int i=0; i< prices.size()-1; i++) 
            if(prices[i + 1] > prices[i]) total += prices[i + 1] - prices[i];
        return total;
    }
};