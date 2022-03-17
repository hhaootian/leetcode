class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(int num, int k, vector<int> &cur, int n) {
        if (cur.size() == k) {
            ans.push_back(cur);
            return;
        }
        for (int i = num; i <= n; i++) {
            cur.push_back(i);
            helper(i + 1, k, cur, n);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        helper(1, k, cur, n);
        return ans;
    }
};