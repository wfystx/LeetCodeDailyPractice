class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        num = 0
        for i in range(1,len(nums)):
            nums[i] = max(nums[i-1]+nums[i],nums[i])
        return max(nums)