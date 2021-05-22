
## Chapter 4

69.  [Sqrt(x)](https://leetcode.com/problems/sqrtx)  

```python
class Solution:
    def mySqrt(self, x: int) -> int:
        left, right = 0, x
        while left <= right:
            mid = (left + right) // 2
            if mid ** 2 == x:
                return mid
            elif mid ** 2 < x:
                left = mid + 1
            else:
                right = mid - 1
        
        return right
```

34.  [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array)  

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        return [self.left_bound(nums, target), self.right_bound(nums, target)]
    
    def left_bound(self, nums, target):
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                right = mid - 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
        
        if left >= len(nums) or nums[left] != target:
            return -1
        return left
    
    def right_bound(self, nums, target):
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
        
        if right < 0 or nums[right] != target:
            return -1
        return right
```

81.  [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii)  

```python
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return True
            if nums[left] == nums[right]:
                left += 1
            elif nums[mid] <= nums[right]:
                if target > nums[mid] and target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                if target >= nums[left] and target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
        
        return False
```

154.  [Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii)  

```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > nums[right]:
                left = mid + 1
            elif nums[mid] < nums[right]:
                right = mid
            else:
                right -= 1

        return nums[left]
```

540.  [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array)  

```python
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1

        while left < right:
            mid = (left + right) // 2
            if nums[mid] == nums[mid - 1]:
                if (mid - left + 1) % 2 == 0:
                    left = mid + 1
                else:
                    right = mid
            elif nums[mid] == nums[mid + 1]:
                if (right - mid + 1) % 2 == 0:
                    right = mid - 1
                else:
                    left = mid
            else:
                return nums[mid]
        
        return nums[left]
```

4.  [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays)  

```python
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
        
        left, right = 0, len(nums1)
        total = len(nums1) + len(nums2)
        while left <= right:
            b1 = (left + right) // 2
            b2 = (total + 1) // 2 - b1
            b1_l = nums1[b1 - 1] if b1 - 1 >= 0 else -float('inf')
            b1_r = nums1[b1] if b1 <= len(nums1) - 1 else float('inf')
            b2_l = nums2[b2 - 1] if b2 - 1 >= 0 else -float('inf')
            b2_r = nums2[b2] if b2 <= len(nums2) - 1 else float('inf')

            if b1_l <= b2_r and b2_l <= b1_r:
                if total % 2 == 0:
                    return (max(b1_l, b2_l) + min(b2_r, b1_r)) / 2
                else:
                    return max(b1_l, b2_l)
            
            else:
                if b1_l > b2_l:
                    right = b1 - 1
                else:
                    left = b1 + 1
        
        return 0.0
```
