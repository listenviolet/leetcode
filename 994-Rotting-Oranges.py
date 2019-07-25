class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        R = len(grid)
        C = len(grid[0])
        
        queue = collections.deque()
        
        for r, row in enumerate(grid):
            for c, val in enumerate(row):
                if val == 2:
                    queue.append((r, c, 0))
        
        def neighbors(r, c):
            for nr, nc in ((r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)):
                if 0 <= nr < R and 0 <= nc < C:
                    yield nr, nc
        
        d = 0
        while queue:
            r, c, d = queue.popleft()
            for nr, nc in neighbors(r, c):
                if grid[nr][nc] == 1:
                    grid[nr][nc] = 2
                    queue.append((nr, nc, d + 1))
        
        if any(1 in row for row in grid):
            return -1
        return d

# Runtime: 44 ms, faster than 38.58% of Python online submissions for Rotting Oranges.
# Memory Usage: 11.7 MB, less than 5.16% of Python online submissions for Rotting Oranges.

# Description:
# In a given grid, each cell can have one of three values:

# the value 0 representing an empty cell;
# the value 1 representing a fresh orange;
# the value 2 representing a rotten orange.
# Every minute, any fresh orange that is adjacent (4-directionally) 
# to a rotten orange becomes rotten.

# Return the minimum number of minutes that must elapse until no cell has a fresh orange.  
# If this is impossible, return -1 instead.

# Example 1:

# Input: [[2,1,1],[1,1,0],[0,1,1]]
# Output: 4
# Example 2:

# Input: [[2,1,1],[0,1,1],[1,0,1]]
# Output: -1
# Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, 
# because rotting only happens 4-directionally.
# Example 3:

# Input: [[0,2]]
# Output: 0
# Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

# Note:

# 1 <= grid.length <= 10
# 1 <= grid[0].length <= 10
# grid[i][j] is only 0, 1, or 2.

# Solution:
# Approach 1: Breadth-First Search
# Intuition

# Every turn, the rotting spreads from each rotting orange to other adjacent oranges. 
# Initially, the rotten oranges have 'depth' 0 [as in the spanning tree of a graph], 
# and every time they rot a neighbor, the neighbors have 1 more depth. 
# We want to know the largest possible depth.

# Algorithm

# We can use a breadth-first search to model this process. 
# Because we always explore nodes (oranges) with the smallest depth first, 
# we're guaranteed that each orange that becomes rotten does 
# so with the lowest possible depth number.

# We should also check that at the end, there are no fresh oranges left.
