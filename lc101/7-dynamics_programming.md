
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

139. [ Word Break](https://leetcode.com/problems/word-break)  

```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [False for i in range(len(s) + 1)]
        # dp[i] -> T/F, s[i-1]
        # dp[i] -> word in wordDict, length, 
        # s[i-length:i] == word YES! dp[i] = dp[i-length]

        dp[0] = True
        for i in range(1, len(s) + 1):
            #dp[i]
            for word in wordDict:
                if s[i-len(word) : i] == word:
                    dp[i] = dp[i] or dp[i - len(word)]
            
        return dp[-1]
```

300. [ Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence)  

```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # 0 ... j ... i
        # dp[i] = max(dp[i], dp[j] + 1)

        n = len(nums)
        dp = [1 for i in range(n)]

        for i in range(n):
            for j in range(0, i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        
        return max(dp)
```

1143. [ Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence)  

```python
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # dp[i][j] 
        '''
          X a b c d e
        X
        a     ? ?
        c     ? NO
        e
        '''

        len1, len2 = len(text1), len(text2)
        dp = [[0 for j in range(len2 + 1)] for i in range(len1 + 1)]

        for i in range(1, len1 + 1):
            for j in range(1, len2 + 1):
                if text1[i-1] == text2[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return dp[-1][-1]
```

416. [ Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum)  

```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 == 1:
            return False

        # i, p, q.... sum() == total / 2
        target = total // 2
        size = len(nums)
        dp = [[False for j in range(target + 1)] for i in range(size + 1)]

        for i in range(size + 1):
            dp[i][0] = True
        
        for i in range(1, size + 1):
            weight = nums[i - 1]
            for j in range(1, target + 1):
                if j-weight >= 0:
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-weight] #!!!!
                else:
                    dp[i][j] = dp[i-1][j]
        
        return dp[-1][-1]
```

474. [ Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes)  

```python
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[0 for j in range(n + 1)] for i in range(m + 1)]

        for string in strs:
            zero, one = string.count("0"), string.count("1")
            # zero
            for i in range(m, zero - 1, -1):
                for j in range(n, one - 1, -1):
                    dp[i][j] = max(dp[i][j], 1 + dp[i-zero][j-one])
        
        return dp[-1][-1]
```

322. [ Coin Change](https://leetcode.com/problems/coin-change)  

```python
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if not coins:
            return -1
        
        size = len(coins)
        dp = [[float('inf') for j in range(amount + 1)] for i in range(size + 1)]

        for i in range(size + 1):
            dp[i][0] = 0
        
        for i in range(1, size + 1):
            weight = coins[i - 1]
            for j in range(1, amount + 1):
                # 0-1 -> dp[i][j] = min(dp[i-1][j], 1 + dp[i-1][j - weight])
                if j - weight >= 0:
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - weight])
                else:
                    dp[i][j] = dp[i-1][j]
        
        return dp[-1][-1] if  dp[-1][-1] < float('inf') else -1
```

72. [ Edit Distance](https://leetcode.com/problems/edit-distance)  

```python
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        #i, j
        #dp[i][j] -> word1[:i] == word2[:j]

        m, n = len(word1), len(word2)
        dp = [[float('inf') for j in range(n + 1)] for i in range(m + 1)]
        for i in range(m + 1):
            dp[i][0] = i
        for j in range(n + 1):
            dp[0][j] = j
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])
        
        return dp[-1][-1]
```

650. 

```python
class Solution:
    def minSteps(self, n: int) -> int:
        #dp[i] 
        #

        dp = [0 for i in range(n + 1)]

        for i in range(2, n + 1):
            dp[i] = i
            for j in range(2, i):
                if i % j == 0:
                    # i = 6, j = 2, dp[2] = a, dp[6] = a + 1 + 2
                    # (i - j) // j + j / j = i // j
                    dp[i] = min(dp[i], dp[j] + i // j)
        
        return dp[-1]
```

10. [ Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching)  

```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        #dp[i][j] = T/F, s[:i], p[:j]
        dp = [[False for j in range(n + 1)] for i in range(m + 1)]

        # init
        dp[0][0] = True

        for j in range(1, n + 1):
            # match 0
            if p[j-1] == "*":
                # j-2, j-1, j
                dp[0][j] = dp[0][j-2]
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                # match 
                if p[j-1] == s[i-1] or p[j-1] == ".":
                    dp[i][j] = dp[i-1][j-1]
                # not match
                elif p[j-1] == "*":
                    '''
                    S: ### (i-1) b(i)
                    P: ### (j-2) b(j-1) *(j)
                    '''
                    if p[j-2] == s[i-1] or p[j-2] == ".":
                        # dp[i][j-2] -> * = 0
                        # dp[i-1][j] -> s中多个重复字符
                        dp[i][j] = dp[i][j-2] or dp[i-1][j]
                    else:
                        dp[i][j] = dp[i][j-2]
        
        return dp[-1][-1]
```

121. [ Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock)  

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # k = 1

        n = len(prices)
        dp = [[0 for _ in range(2)] for i in range(n + 1)]
        
        dp[0][1] = -float('inf')

        for i in range(1, n + 1):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i - 1])
            dp[i][1] = max(dp[i-1][1], -prices[i - 1])
        
        return dp[-1][0]
```

188. [ Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv)  

```python
class Solution:
    def maxProfit(self, K: int, prices: List[int]) -> int:
        n = len(prices)
        dp = [[[0 for _ in range(2)] for k in range(K + 1)] for i in range(n + 1)]
        
        # init
        for k in range(K + 1):
            dp[0][k][0] = 0
            dp[0][k][1] = -float('inf')
        
        for i in range(1, n + 1):
            dp[i][0][0] = 0
            dp[i][0][1] = -float('inf')

            for k in range(1, K + 1):
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i - 1])
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i - 1])

        return dp[n][K][0]
```

309. [ Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown)  

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)

        dp = [[0 for _ in range(2)] for i in range(n + 1)]
        dp[0][1] = -float('inf')

        for i in range(1, n + 1):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i - 1])
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i - 1])

        return dp[n][0]
```

213. [ House Robber II](https://leetcode.com/problems/house-robber-ii)  

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        #dp[i] = nums[i-1] + dp[i-2], dp[i-1]
        def helper(nums):
            N = len(nums)
            dp = [0 for i in range(N + 1)]
            for i in range(1, N + 1):
                dp[i] = max(dp[i-1], nums[i-1] + dp[i-2])
            
            return dp[-1]
        
        if not nums:
            return 0
        
        if len(nums) == 1:
            return nums[0]
        
        return max(helper(nums[:-1]), helper(nums[1:]))
```

53. [Maximum Subarray](https://leetcode.com/problems/maximum-subarray)  

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        #dp[i]
        #dp[i] = max(dp[i-1] + nums[i-1], nums[i-1])

        n = len(nums)
        dp = [0 for i in range(n + 1)]

        for i in range(1, n + 1):
            dp[i] = max(dp[i-1] + nums[i-1], nums[i-1])
        
        return max(dp[1:])
```

343. [Integer Break](https://leetcode.com/problems/integer-break)  

```python
class Solution:
    def integerBreak(self, n: int) -> int:
        #dp[i] 
        #dp[i] = max(dp[i], j * (i - j), j * dp[i - j])

        dp = [0 for i in range(n + 1)]

        for i in range(1, n + 1):
            for j in range(1, i):
                dp[i] = max([dp[i], j * (i - j), j * dp[i-j]])
        
        return dp[-1]     
```

583. [Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings)  

```python
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        #dp[i][j] 

        m, n = len(word1), len(word2)
        dp = [[0 for j in range(n + 1)] for i in range(m + 1)]

        # init
        for i in range(m + 1):
            dp[i][0] = i
        
        for j in range(n + 1):
            dp[0][j] = j

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if word1[i-1] != word2[j-1]:
                    dp[i][j] = min([dp[i-1][j-1] + 2, dp[i-1][j] + 1, dp[i][j-1] + 1])
                else:
                    dp[i][j] = min([dp[i-1][j-1], dp[i-1][j] + 1, dp[i][j-1] + 1])

        return dp[-1][-1]
```

646. [Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain)  

```python
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        #dp[i] 
        pairs = sorted(pairs, key = lambda x: (x[0], x[1]))
        n = len(pairs)
        dp = [1 for i in range(n + 1)]

        for i in range(2, n + 1):
            end = pairs[i - 1]
            for j in range(1, i):
                start = pairs[j - 1]
                if start[1] < end[0]:
                    dp[i] = max(dp[i], dp[j] + 1)
        
        return dp[-1]
```

376. [Wiggle Subsequence](https://leetcode.com/problems/wiggle-subsequence)  

```python
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        up = [0 for i in range(n + 1)] #up[i]
        down = [0 for i in range(n + 1)]

        # init
        up[1] = 1
        down[1] = 1

        for i in range(2, n + 1):
            if nums[i-1] > nums[i-2]:
                up[i] = max(up[i-1], down[i-1] + 1)
                down[i] = down[i-1]
            
            elif nums[i-1] < nums[i-2]:
                up[i] = up[i-1]
                down[i] = max(down[i-1], up[i-1] + 1)
            
            else:
                up[i] = up[i-1]
                down[i] = down[i-1]
        
        return max(up[-1], down[-1])
```

494. [Target Sum](https://leetcode.com/problems/target-sum)  

```python
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        if target > sum(nums):
            return 0
        
        #dp[i][j] 
        total = sum(nums)
        size = 2 * total + 1
        dp = [[0 for j in range(size)] for i in range(len(nums) + 1)]
        # -3, -2, -1, 0, 1, 2, 3
        #
        #

        # init
        # !!! total
        dp[1][total + nums[0]] += 1
        dp[1][total - nums[0]] += 1

        for i in range(1, len(nums) + 1):
            val = nums[i - 1]
            for j in range(0, size):
                if j + val >= 0 and j + val <= size - 1:
                    dp[i][j] += dp[i-1][j + val]
                if j - val >= 0 and j - val <= size - 1:
                    dp[i][j] += dp[i-1][j - val]

        return dp[-1][total + target]
```

714. [Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee)  

```python
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)
        dp = [[0 for _ in range(2)] for i in range(n + 1)]

        # init
        dp[0][1] = -float('inf')

        for i in range(1, n + 1):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i - 1] - fee)
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i - 1])

        return dp[n][0]
```
