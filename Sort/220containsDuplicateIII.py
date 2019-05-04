#Bucket sorted

class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        buckets = {}
        for i, val in enumerate(nums):
            if t:
                bucketnum, offset = val/t, 1
            else:
                bucketnum, offset = val, 0
            for idx in range(bucketnum-offset,bucketnum+offset+1):
                if idx in buckets and abs(buckets[idx]-nums[i]) <= t:
                    return True
            
            buckets[bucketnum] = nums[i]
            if len(buckets) > k:
                if t:
                    del buckets[nums[i-k]/t]
                else:
                    del buckets[nums[i-k]]
        return False