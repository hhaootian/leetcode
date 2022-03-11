class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int need[26] = {0};
        int have[26] = {0};
        for (auto letter : ransomNote)
            need[letter - 'a']++;
        for (auto letter : magazine)
            have[letter - 'a']++;
        
        for (int i = 0; i < 26; i++) {
            if (need[i] > have[i])
                return false;
        }
        return true;
    }
};