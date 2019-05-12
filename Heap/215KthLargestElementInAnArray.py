class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        res = []
        for i in nums:
            heapq.heappush(res,-i)
            
        for i in range(k-1):
            heapq.heappop(res)
            
        return -heapq.heappop(res)