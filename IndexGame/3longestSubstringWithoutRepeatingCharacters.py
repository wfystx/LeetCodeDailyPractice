#index

#save the index if it not appears in dic
#if appears later, i+1

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        start = nums = 0
        dic = {}
        for i in xrange(len(s)):
            if s[i] in dic and start <= dic[s[i]]:
                start = dic[s[i]]+1
            else:
                nums = max(nums,i-start+1)
            dic[s[i]] = i
        return nums