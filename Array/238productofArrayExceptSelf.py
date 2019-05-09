class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = []
        p = 1
        for i in range(len(nums)):
            res.append(p)
            p *= nums[i]
        p = 1
        for i in range(len(nums)-1,-1,-1):
            res[i] *= p
            p *= nums[i]
            
        return res