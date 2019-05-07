class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        low = float("inf")
        res = 0
        for i in prices:
            if i < low:
                low = i
            elif i - low > res:
                res = i - low
            else:
                pass
        return res