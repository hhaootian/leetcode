
## Chapter 3

167.  [ Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted)  

```python
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1
        while left < right:
            cur = numbers[left] + numbers[right]
            if cur == target:
                return [left + 1, right + 1]
            elif cur < target:
                left += 1
            else:
                right -= 1
        
        return [-1, -1]
```

88.  [ Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array)  

```python
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        left, right = m - 1, n - 1
        end = m + n - 1

        while end >= 0 and left >= 0 and right >= 0:
            if nums1[left] >= nums2[right]:
                nums1[end] = nums1[left]
                left -= 1
            else:
                nums1[end] = nums2[right]
                right -= 1
            end -= 1
        
        while right >= 0:
            nums1[end] = nums2[right]
            right -= 1
            end -= 1
        
```

142.  [ Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii)  

```python
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if not head:
            return None
        
        slow, fast = head, head
        while fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                break
        
        if fast == None or fast.next == None:
            return None
        
        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next
        
        return slow
```

76.  [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring)  

```python
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        required = collections.defaultdict(int)
        for char in t:
            required[char] += 1
        
        have = collections.defaultdict(int)
        left, right = 0, 0
        count = 0
        ans = (float('inf'), None, None)

        while right < len(s):
            cur = s[right]
            if cur in required:
                have[cur] += 1
                if have[cur] == required[cur]:
                    count += 1
            
            while count == len(required):
                if right - left + 1 < ans[0]:
                    ans = (right - left + 1, left, right)
                
                prev = s[left]
                if prev in required:
                    have[prev] -= 1
                    if have[prev] < required[prev]:
                        count -= 1
            
                left += 1
            
            right += 1
        
        if ans[0] == float('inf'):
            return ""
        else:
            return s[ans[1]:ans[2] + 1]
```

633.  [Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers)  

```python
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a = 0
        import math
        b = int(math.sqrt(c) + 1)

        while a <= b:
            cur = a ** 2 + b ** 2
            if cur == c:
                return True
            elif cur < c:
                a += 1
            else:
                b -= 1
        
        return False
```

680.  [Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii)  

```python
class Solution:
    def validPalindrome(self, s: str, count = 0) -> bool:
        left = 0
        right = len(s) - 1

        while left < right:
            if s[left] == s[right]:
                left += 1
                right -= 1
            else:
                count += 1
                if count >= 2:
                    return False
                return self.validPalindrome(s[left + 1 : right + 1], count) \
                    or self.validPalindrome(s[left : right], count)
        
        return True
```

524.  [ Longest Word in Dictionary through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting) 

```python
class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        ans = []

        for word in dictionary:
            left, right = 0, 0
            while left < len(s) and right < len(word):
                if s[left] == word[right]:
                    left += 1
                    right += 1
                else:
                    left += 1
            
            if right == len(word):
                ans.append(word)
        
        if len(ans) == 0:
            return ""
        else:
            ans = sorted(ans, key = lambda x : (-len(x), x))
            return ans[0]
```
