class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        res , p = 0, 'I'
        dic = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        for i in s[::-1]:
            if dic[i] < dic[p]:
                res -= dic[i]
            else:
                res += dic[i]
            p = i
        return res