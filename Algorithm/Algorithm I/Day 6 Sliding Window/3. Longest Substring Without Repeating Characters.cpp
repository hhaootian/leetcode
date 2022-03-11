class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> cnt;
        int ans = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (cnt.count(s[i])){
                cnt.erase(s[left]);
                left++;
            }
            ans = max(ans, i - left + 1);
            cnt.insert(s[i]);
        }
        return ans;
    }
};