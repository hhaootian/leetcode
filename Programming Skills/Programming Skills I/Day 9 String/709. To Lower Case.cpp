class Solution {
public:
    string toLowerCase(string s) {
        string ans;
        for (auto c : s) {
            ans += tolower(c);
        }
        return ans;
    }
};