class Solution(object):
    def findLongestWord(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """
        #myc
        def isValid(s,target):
            i, j = 0, 0
            while i < len(s) and j < len(target):
                if s[i] == target[j]:
                    j += 1
                i += 1
            return  j == len(target)
        
        longest = ''
        for i in d:
            l1, l2 = len(longest), len(i)
            if l1 > l2 or (l1 == l2 and ord(longest[0]) < ord(i[0])):
                continue
            if isValid(s,i):
                longest = i
        return longest