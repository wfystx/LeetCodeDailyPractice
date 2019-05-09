class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return max(nums)
        else:
            res = [0 for _ in range(len(nums))]
            res[0] = nums[0]
            res[1] = max(nums[0],nums[1])
            for i in range(2,len(nums)):
                res[i] = max(res[i-1],res[i-2]+nums[i])
        return res[-1]