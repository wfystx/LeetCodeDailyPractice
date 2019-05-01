#Key: array
#Dictionary

#because the array is disordered, so I should remember the number
#and the index after I traval 

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dic = {}
        for i in range(len(nums)):
            if nums[i] not in dic:
                dic[target - nums[i]] = i
            else:
                return [dic[nums[i]],i]