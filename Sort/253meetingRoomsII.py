class Solution(object):
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        start, end = [], []
        for i in intervals:
            start.append(i[0])
            end.append(i[1])
            
        start.sort()
        end.sort()
        s,e = 0, 0 
        res, available = 0, 0 
        while s < len(start):
            if start[s] < end[e]:
                if available:
                    available -= 1
                else:
                    res += 1
                s += 1
            else:
                available += 1
                e += 1
        return res