class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty()) return 0;
        for(int i=1; i<costs.size(); i++){
            costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] += min(costs[i-1][0], costs[i-1][1]);
        }
        return min(costs.back()[0], min(costs.back()[1],costs.back()[2]));
    }
};