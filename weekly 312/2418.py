class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        
        index = list(range(len(names)))
        index = sorted(index, key = lambda x : heights[x], reverse=True)
        
        ans = []
        for idx in index:
            ans.append(names[idx])
        
        return ans
    