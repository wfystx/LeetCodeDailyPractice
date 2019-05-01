#Recursion

class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        def check(i,j):
            if 0 <= i < len(grid) and 0 <= j < len(grid[0]) and grid[i][j] == '1':
                grid[i][j] = '0'
                check(i-1,j)
                check(i+1,j)
                check(i,j-1)
                check(i,j+1)
                return 1
            return 0
        return sum(check(i,j) for i in range(len(grid)) for j in range(len(grid[0])))