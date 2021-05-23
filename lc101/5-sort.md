
## Chapter 5

215.  [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array)  

```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = []
        for num in nums:
            heapq.heappush(heap, -1 * num)
        
        for i in range(k - 1):
            heapq.heappop(heap)
        
        return -1 * heapq.heappop(heap)
```

347.  [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements)  

```python
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dic = collections.defaultdict(int)
        for num in nums:
            dic[num] += 1
        
        sort = sorted(dic.items(), key = lambda x : x[1], reverse = True)
        ans = []
        index = 0
        while len(ans) < k:
            ans.append(sort[index][0])
            index += 1
        
        return ans
```

451.  [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency)  

```python
class Solution:
    def frequencySort(self, s: str) -> str:
        dic = collections.defaultdict(int)
        for char in s:
            dic[char] += 1
        
        sort = sorted(dic.items(), key = lambda x : x[1], reverse = True)
        ans = ""
        for item in sort:
            char, freq = item
            ans += char * freq
        
        return ans
```

75.  [Sort Colors](https://leetcode.com/problems/sort-colors)  

```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        red, blue = 0, len(nums) - 1
        white = 0

        while white <= blue:
            if nums[white] == 1:
                white += 1
            
            elif nums[white] == 0:
                nums[red], nums[white] = nums[white], nums[red]
                red += 1
                white += 1
            
            else:
                nums[blue], nums[white] = nums[white], nums[blue]
                blue -= 1
```
