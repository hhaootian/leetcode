
## Chapter 7

70. [ Climbing Stairs](https://leetcode.com/problems/climbing-stairs)  

```python
class Solution:
    def climbStairs(self, n: int) -> int:
        ans = [0 for i in range(n + 1)]
        ans[0] = 1
        ans[1] = 1
        for i in range(2, n + 1):
            # prev ans[i-1] + step 1
            # prev ans[i-2] + step 2
            ans[i] = ans[i - 1] + ans[i - 2]
        
        return ans[-1]
```

198. [ House Robber](https://leetcode.com/problems/house-robber)  

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0 for i in range(n + 1)]

        for i in range(1, n + 1):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i - 1])
        
        return dp[-1]
```

413. [ Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices)  

```python
class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 3:
            return 0
        
        dp = [0 for i in range(n)]
        for i in range(2, n):
            if nums[i] - nums[i-1] == nums[i-1] - nums[i-2]:
                dp[i] = dp[i-1] + 1
        
        return sum(dp)
```

64. [ Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum)  

```python
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        # [i, j]
        # min([i-1, j], [i, j-1]) + grid[i][j]

        m, n = len(grid), len(grid[0])
        dp = [[0 for i in range(n)] for j in range(m)]

        # init
        dp[0][0] = grid[0][0]

        for j in range(1, n):
            dp[0][j] = dp[0][j-1] + grid[0][j]

        for i in range(1, m):
            dp[i][0] = dp[i-1][0] + grid[i][0]
        
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
        
        return dp[-1][-1]
```

542. [ 01 Matrix](https://leetcode.com/problems/01-matrix)  

```python
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        m, n = len(matrix), len(matrix[0])
        dp = [[float('inf') for j in range(n)] for i in range(m)]

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    dp[i][j] = 0
        
        for i in range(m):
            for j in range(n):
                if i - 1 >= 0:
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + 1)
                if j - 1 >= 0:
                    dp[i][j] = min(dp[i][j], dp[i][j-1] + 1)

        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if i + 1 <= m - 1:
                    dp[i][j] = min(dp[i][j], dp[i+1][j] + 1)
                if j + 1 <= n - 1:
                    dp[i][j] = min(dp[i][j], dp[i][j+1] + 1)
        
        return dp
```

221. [ Maximal Square](https://leetcode.com/problems/maximal-square)  

```python
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        # [i-1][j-1], [i-1][j]
        # [i][j-1],   [i][j]
        
        m, n = len(matrix), len(matrix[0])
        dp = [[0 for j in range(n)] for i in range(m)]

        for i in range(m):
            if matrix[i][0] == "1":
                dp[i][0] = 1
        
        for j in range(n):
            if matrix[0][j] == "1":
                dp[0][j] = 1
        
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == "1":
                    dp[i][j] = min([dp[i-1][j-1], dp[i-1][j], dp[i][j-1]]) + 1
        
        result = 0
        for i in range(m):
            for j in range(n):
                result = max(result, dp[i][j])

        return result ** 2
```

279. [ Perfect Squares](https://leetcode.com/problems/perfect-squares)  

```python
class Solution:
    def numSquares(self, n: int) -> int:
        # dp[i] = min(dp[i], 1 + min(dp[i - 1], dp[i - 4], dp[i - 9] .... ))
        dp = [float('inf') for i in range(n + 1)]
        dp[0] = 0

        for i in range(1, n + 1):
            j = 1
            while j * j <= i: # i - j ** 2 >= 0
                dp[i] = min(dp[i], dp[i - j * j] + 1)
                j += 1
        
        return dp[-1]
```

91. [ Decode Ways](https://leetcode.com/problems/decode-ways)  

```python
class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == "0":
            return 0
        
        n = len(s)
        dp = [0 for i in range(n + 1)]
        dp[0] = 1
        dp[1] = 1

        # s:   1 1 1
        #dp: 0 0 0 0
        # dp[i] -> s[i-1]

        for i in range(2, n+1):
            if s[i-1] == "0":
                dp[i] = 0
            else:
                dp[i] = dp[i-1]
            
            double = int(s[i - 2 : i])
            if double >= 10 and double <= 26:
                dp[i] += dp[i-2]
        
        return dp[-1]
```
