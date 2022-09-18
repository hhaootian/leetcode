class Solution:
    def longestContinuousSubstring(self, s: str) -> int:
        ans = 0
        for i in range(len(s)):
            cur = s[i]
            length = 0
            while i + length < len(s) and ord(s[i + length]) - ord(s[i]) == length:
                length += 1
            ans = max(ans, length)
        
        return ans
    