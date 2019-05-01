#from the center check whether or not is a palindrome

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        def check(s,l,r):
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            return s[l+1:r]
        
        res = ''
        for i in range(len(s)):
            temp = check(s,i,i)
            if len(temp) > len(res):
                res = temp
            temp = check(s,i,i+1)
            if len(temp) > len(res):
                res = temp
        return res