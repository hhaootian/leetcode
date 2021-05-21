
## Chapter 2

455.  [Assign Cookies](https://leetcode.com/problems/assign-cookies)

```python
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g = sorted(g)
        s = sorted(s)
        child, cookie = 0, 0
        ans = 0

        while child < len(g) and cookie < len(s):
            if g[child] <= s[cookie]:
                ans += 1
                child += 1
            cookie += 1
        
        return ans
```

135.  [Candy](https://leetcode.com/problems/candy)  

```python
class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        nums = [1 for i in range(n)]

        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                nums[i] = nums[i - 1] + 1
        
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                nums[i] = max(nums[i], nums[i + 1] + 1)
        
        return sum(nums)
```

435.  [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals)  

```python
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        
        intervals = sorted(intervals, key = lambda x : x[1])
        ans = 0
        end = intervals[0][1]

        for i in range(1, len(intervals)):
            if intervals[i][0] < end:
                ans += 1
            else:
                end = intervals[i][1]
        
        return ans
```

605.  [Can Place Flowers](https://leetcode.com/problems/can-place-flowers)  

```python
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        flowerbed = [0] + flowerbed + [0]
        ans = 0

        for i in range(1, len(flowerbed) - 1):
            if flowerbed[i - 1] == 0 and flowerbed[i] == 0 and flowerbed[i + 1] == 0:
                flowerbed[i] = 1
                ans += 1
            if ans >= n:
                return True
        
        return False
```

452.  [Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons)  

```python
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0
        
        ans = 1
        points = sorted(points, key = lambda x : x[1])

        end = points[0][1]
        for i in range(1, len(points)):
            if points[i][0] > end:
                ans += 1
                end = points[i][1]
        
        return ans
```

763.  [Partition Labels](https://leetcode.com/problems/partition-labels)  

```python
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        dic = {}
        for i in range(len(s)):
            if s[i] not in dic:
                dic[s[i]] = i
            else:
                dic[s[i]] = max(dic[s[i]], i)
        
        end = dic[s[0]]
        index = 0
        ans = []

        while index < len(s):
            if index == end:
                ans.append(index)
                if index + 1 < len(s):
                    end = dic[s[index + 1]]
            
            else:
                end = max(end, dic[s[index]])

            index += 1
        
        ans.insert(0, -1)
        return [ans[i] - ans[i-1] for i in range(1, len(ans))]
```

122.  [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii)  

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                profit += prices[i] - prices[i - 1]
        
        return profit
```

406.  [Queue Reconstruction by Height](https://leetcode.com/problems/queue-reconstruction-by-height)  

```python
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people = sorted(people, key = lambda x : (-x[0], x[1]))
        ans = []

        for item in people:
            ans.insert(item[1], item)
        
        return ans
```

665.  [Non-decreasing Array](https://leetcode.com/problems/non-decreasing-array)  

```python
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        if not nums or len(nums) == 1:
            return True

        count = 0
        for i in range(1, len(nums)):
            if nums[i] >= nums[i - 1]:
                continue
            if i - 2 >= 0 and nums[i - 2] > nums[i]:
                nums[i] = nums[i - 1]
            else:
                nums[i - 1] = nums[i]
            count += 1
            if count == 2:
                return False
        
        return True
```

