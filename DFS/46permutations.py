class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def dfs(nums, path, res):
            if not nums:
                res.append(path)
            for i in range(len(nums)):
                print(nums[:i]+nums[i+1:])
                dfs(nums[:i]+nums[i+1:], path+[nums[i]],res)
        
        res = []
        dfs(nums,[],res)
        return 0