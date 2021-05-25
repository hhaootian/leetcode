
## Chapter 6

695. [Max Area of Island](https://leetcode.com/problems/max-area-of-island)  

```python
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        maxArea = 0
        row, col = len(grid), len(grid[0])
        visited = [[False for i in range(col)] for j in range(row)]
        direction = [[0, -1], [0, 1], [-1, 0], [1, 0]]

        def dfs(i, j):
            if visited[i][j]:
                return 0
            visited[i][j] = True
            currentArea = 1
            for direc in direction:
                newI, newJ = i + direc[0], j + direc[1]
                if newI >= 0 and newI <= row - 1 and newJ >= 0 and newJ <= col - 1 and grid[newI][newJ] == 1:
                    currentArea += dfs(newI, newJ)
            return currentArea
        
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    area = dfs(i, j)
                    maxArea = max(maxArea, area)
        
        return maxArea
```

547. [ Number of Provinces](https://leetcode.com/problems/number-of-provinces)  

```python
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        n = len(M)
        visited = [False for i in range(n)]
        ans = 0

        def dfs(i):
            if visited[i]:
                return
            
            visited[i] = True
            for j in range(n):
                if j != i and M[i][j] == 1:
                    dfs(j)
        
        for i in range(n):
            if not visited[i]:
                ans += 1
                dfs(i)
        
        return ans
```

417. [ Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow)  

```python
class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return []
        
        row, col = len(matrix), len(matrix[0])
        pacific = set()
        atlantic = set()
        directions = [[0, 1], [0, -1], [-1, 0], [1, 0]]

        def dfs(visited, i, j):
            visited.add((i, j))
            for direc in directions:
                newI, newJ = i + direc[0], j + direc[1]
                if 0 <= newI < row and 0 <= newJ < col and (newI, newJ) not in visited and matrix[newI][newJ] >= matrix[i][j]:
                    dfs(visited, newI, newJ)
        
        for i in range(row):
            dfs(pacific, i, 0)
            dfs(atlantic, i, col - 1)
        
        for i in range(col):
            dfs(pacific, 0, i)
            dfs(atlantic, row - 1, i)
    
        return list(pacific.intersection(atlantic))
```

