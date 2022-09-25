class Solution:
    def goodIndices(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        non_increasing = collections.defaultdict(int)
        non_decreasing = collections.defaultdict(int)
        
        non_increasing[0] = 1
        non_decreasing[0] = 1

        for i in range(1, len(nums)):
            if nums[i] <= nums[i - 1]:
                non_increasing[i] = non_increasing[i - 1] + 1
            else:
                non_increasing[i] = 1
            
            if nums[i] >= nums[i - 1]:
                non_decreasing[i] = non_decreasing[i - 1] + 1
            else:
                non_decreasing[i] = 1
        
        ans = []
        for i in range(k, n - k):
            if non_increasing[i - 1] >= k and non_decreasing[i + k] >= k:
                ans.append(i)
        return ans
    