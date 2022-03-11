class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (auto letter : s) {
            map[letter]++;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]] == 1)
                return i;
        }
        return -1;
    }
};