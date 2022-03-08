class Solution {
public:
    int helper(string s1, string s2, int start) {
        for (int i = start; i < s1.size(); i++) {
            if (s1[i] != s2[i])
                return i;
        }
        return -1;
    }

    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        
        int diff1 = helper(s1, s2, 0);
        if (diff1 == -1)
            return true;
        
        int diff2 = helper(s1, s2, diff1 + 1);
        if (diff2 == -1)
            return false;
        
        return s1[diff1] == s2[diff2] && s1[diff2] == s2[diff1] && (helper(s1, s2, diff2 + 1) == -1);
    }
};