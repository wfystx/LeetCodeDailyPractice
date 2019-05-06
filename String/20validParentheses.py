class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        arr = []
        
        for i in s:
            if i == '(' or i == '{' or i == '[':
                arr.append(i)
            if (i == ')' or i == '}' or i == ']') and not arr:
                print(1)
                return False
            if i == ')':
                if arr.pop() != '(':
                    print(2)
                    return False
            elif i == ']':
                if arr.pop() != '[':
                    print(3)
                    return False
            elif i == '}':
                if arr.pop() != '{':
                    print(4)
                    return False
            else:
                pass
        return arr == []