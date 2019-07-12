class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        gasSum, costSum, tank, start = 0, 0, 0, 0;
        for i in range(len(gas)):
            gasSum += gas[i]
            costSum += cost[i]
            tank += gas[i] - cost[i]
            if tank < 0:
                start = i + 1
                tank = 0
        return start if gasSum >= costSum else -1