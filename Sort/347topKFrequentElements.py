class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        counter = collections.Counter()
        for i in nums:
            counter[i] += 1
        bucket = [[] * _ for _ in range(max(counter.values())+1)]
        for i in counter.keys():
            bucket[counter[i]].append(i)
        ans = []
        i = len(bucket)-1
        while len(ans) < k and i >= 0:
            if bucket[i] == None:
                continue
            if len(bucket[i]) <= k-len(ans):
                ans += bucket[i]
            else:
                ans += bucket[:k-len(ans)+1]
            i -= 1
        return ans
        
        