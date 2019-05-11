class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        small,large = -1,-1
        
        for i in range(len(nums)-2,-1,-1):
            if nums[i] < nums[i+1]:
                small = i
                break
        if small == -1:
            nums.reverse()
        else:
            for j in range(len(nums)-1,-1,-1):
                if nums[j] > nums[small]:
                    large = j
                    break
                    
            nums[small],nums[large] = nums[large],nums[small]
            i = small+1
            j = len(nums)-1
            while i < j:
                nums[i],nums[j] = nums[j],nums[i]
                i += 1
                j -= 1