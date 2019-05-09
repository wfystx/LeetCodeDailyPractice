class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mi, mx, res =  nums[0],nums[0],nums[0]
        for i in range(1,len(nums)):
            temp = mi
            mi = min(mi*nums[i],nums[i],mx*nums[i])
            mx = max(temp*nums[i],nums[i],mx*nums[i])
            if mx > res:
                res = mx
        return res