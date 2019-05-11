class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        res = 0
        dic = {}
        for i in S:
            if i not in dic:
                dic[i] = 1
            else:
                dic[i] += 1
        for i in dic.keys():
            if i in J:
                res += dic[i]
                
        return res