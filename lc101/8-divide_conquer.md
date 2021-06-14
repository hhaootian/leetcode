
## Chapter 8

241.  [Different Ways to Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses)  

```python
class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        ans = []

        for i in range(len(expression)):
            cur = expression[i]

            if cur in ["+", "-", "*"]:
                left = self.diffWaysToCompute(expression[:i])
                right = self.diffWaysToCompute(expression[i+1:])

                for l in left:
                    for r in right:
                        if cur == "+":
                            ans.append(l + r)
                        if cur == "-":
                            ans.append(l - r)
                        if cur == "*":
                            ans.append(l * r)
        
        if not ans:
            return [int(expression)]
        else:
            return ans
```

932. [Beautiful Array](https://leetcode.com/problems/beautiful-array)  

```python
class Solution:
    def beautifulArray(self, n: int) -> List[int]:
        memo = {1 : [1]}

        def helper(n):
            if n in memo:
                return memo[n]
            memo[n] = [2 * x - 1 for x in helper((n + 1) // 2)] + \
                        [2 * x for x in helper(n // 2)]
            return memo[n]

        return helper(n)
```

312. [Burst Balloons](https://leetcode.com/problems/burst-balloons)  

```python
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        # (i, j) -> k, nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]
        nums = [1] + nums + [1]
        n = len(nums)

        dp = [[0 for i in range(n)] for j in range(n)]

        for i in range(n-1, -1, -1):
            for j in range(i + 1, n):
                for k in range(i + 1, j):
                    dp[i][j] = max(dp[i][j], nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j])

        return dp[0][n - 1]
```
