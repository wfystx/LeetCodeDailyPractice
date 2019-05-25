class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, tank = 0, gasSum = 0, costSum = 0;
        for(int i=0; i<gas.size(); i++){
            gasSum += gas[i];
            costSum += cost[i];
            tank = tank + gas[i] - cost[i];
            if(tank < 0){
                start = i+1;
                tank = 0;
            }
        }
        return gasSum < costSum ? -1 : start;
    }
};