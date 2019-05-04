#三分法

class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        zero, one, two = -1, 0, len(nums)
        
        while one < two:
            if nums[one] == 0:
                zero += 1
                nums[zero], nums[one] = nums[one], nums[zero]
                one += 1
            elif nums[one] == 2:
                two -= 1
                nums[two],nums[one] = nums[one],nums[two]
            else:
                one += 1