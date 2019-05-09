class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        def check(i,j):
            return (j-i)*min(height[i],height[j])
        
        res = 0
        i, j = 0, len(height)-1
        while i < j:
            res = max(res,check(i,j))
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return res