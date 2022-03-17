class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        backtrack(s, 0, ans);
        return ans;
    }

    void backtrack(string &s, int i, vector<string> &ans) {
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }
        char c = s[i];
        s[i] = islower(c) ? toupper(c) : tolower(c);
        backtrack(s, i + 1, ans);
        if (isalpha(c)) {
            s[i] = c;
            backtrack(s, i + 1, ans);
        }
    }
};