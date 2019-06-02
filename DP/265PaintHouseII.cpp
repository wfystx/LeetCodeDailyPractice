class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty()) return 0;
        int min1(-1), min2(-1), last1, last2;
        for(int i=0; i<costs.size(); i++){
            last1 = min1; last2 = min2;
            min1 = -1; min2 = -1;
            for(int j=0; j<costs[0].size(); j++){
                if(j != last1) 
                    costs[i][j] += last1 < 0 ? 0 : costs[i-1][last1];
                else costs[i][j] += last2 < 0 ? 0 : costs[i-1][last2];
                if(min1 < 0 || costs[i][j] < costs[i][min1]) {
                    min2 = min1;
                    min1 = j;
                }else if(min2 < 0 || costs[i][j] < costs[i][min2]) min2 = j;
            }
        }
        return costs.back()[min1];
    }
};