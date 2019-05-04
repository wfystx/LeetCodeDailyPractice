#sort

class Solution(object):
    def kClosest(self, points, K):
        """
        :type points: List[List[int]]
        :type K: int
        :rtype: List[List[int]]
        """
        points.sort(key = lambda p: p[0]**2+p[1]**2)
        return points[:K]
        