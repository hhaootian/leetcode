class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        max_val = -1
        cnt = 0
        ans = 1
        seen = collections.defaultdict(int)

        for i, num in enumerate(nums):
            if num > max_val:
                max_val = num
                cnt = 1
                seen[max_val] = max(1, seen[max_val])
            elif num == max_val:
                cnt += 1
                seen[max_val] = max(seen[max_val], cnt)
            else:
                cnt = 0
        
        return seen[max_val]
    