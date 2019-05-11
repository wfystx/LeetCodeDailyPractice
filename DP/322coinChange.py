class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        if amount < 1:
            return 0
        res = [float('inf')]*(amount+1)
        res[0] = 0
        for i in range(1,amount+1):
            for j in coins:
                if j <= i:
                    res[i] = min(res[i],res[i-j]+1)
        
        if res[amount] <= amount:
            return res[amount]
        else:
            return -1