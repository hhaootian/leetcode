class Solution {
public:
    bool isAnagram(string s, string t) {
        int cs[26] = {0};
        int ct[26] = {0};
        for (auto letter : s)
            cs[letter - 'a']++;
        for (auto letter : t)
            ct[letter - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (cs[i] != ct[i])
                return false;
        }
        return true;
    }
};