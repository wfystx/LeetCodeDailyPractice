class Solution(object):
    def totalFruit(self, tree):
        """
        :type tree: List[int]
        :rtype: int
        """
        dic = collections.Counter()
        start, res =0,0
        for i in range(len(tree)):
            dic[tree[i]] += 1
            while len(dic) > 2:
                dic[tree[start]] -= 1
                if dic[tree[start]] == 0:
                    del dic[tree[start]]
                start += 1
            res = max(res,i-start+1)
        return res
    
    