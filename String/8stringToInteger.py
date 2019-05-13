class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        str = str.lstrip()
        if not str:
            return 0
        
        count = 0
        flag = 0
        i = 0
        
        if str[i] == '+':
            i += 1
        elif str[i] == '-':
            flag = 1
            i += 1
        elif not str[i].isdigit():
            return 0
        
        while i < len(str) and str[i].isdigit():
            count *= 10
            count += int(str[i])
            i += 1
        if flag:
            count = - count
        
        if count >= 2**31-1:
            return 2**31-1
        elif count <= -2**31:
            return -2**31
        else:
            return count
        