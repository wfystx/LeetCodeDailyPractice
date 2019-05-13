class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        x = str(x)
        i, j = 0, len(x)-1
        
        while i < j:
            if x[i] == x[j]:
                i += 1
                j -= 1
            else:
                return False
        return True