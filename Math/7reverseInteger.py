class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign = 0
        if x < 0:
            sign = 1
            x = abs(x)
        
        l, ans = [], 0
        while x > 0:
            l.append(x%10)
            x = x//10
        
        for i in range(len(l)):
            ans += l[i]*10**(len(l)-i-1)
        
        if sign:
            if ans > 2**31:
                return 0
            return -ans
        else:
            if ans > 2**31-1:
                return 0
            return ans