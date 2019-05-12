class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        counter = collections.Counter()
        res, temp = 0, 0
        counter[0] = 1
        
        for i in nums:
            temp += i
            res += counter[temp-k]
            counter[temp] += 1
        return res