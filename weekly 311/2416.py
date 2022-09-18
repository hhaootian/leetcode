class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        cnt = collections.defaultdict(int)
        for word in words:
            for i in range(1, len(word) + 1):
                cur = word[:i]
                cnt[cur] += 1
        
        ans = []
        for word in words:
            cur = 0
            for i in range(1, len(word) + 1):
                cur += cnt[word[:i]]
            ans.append(cur)
        return ans
    