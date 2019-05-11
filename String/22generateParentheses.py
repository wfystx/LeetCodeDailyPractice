class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ans = []
        
        def check(s = '', left = 0, right = 0):
            if len(s) == 2*n:
                ans.append(s)
                return
            if left < n:
                check(s+'(',left+1,right)
            if right < left:
                check(s+')',left,right+1)
        check()         
        return ans