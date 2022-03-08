class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) 
            return {{1}};
        if (numRows == 2)
            return {{1}, {1, 1}};
        
        vector<vector<int>> ans = {{1}, {1, 1}};

        for (int i = 3; i < numRows + 1; i++) {
            vector<int> cur = {1};
            for (int j = 1; j < ans[i-2].size(); j++)
                cur.push_back(ans[i-2][j-1] + ans[i-2][j]);
            cur.push_back(1);
            ans.push_back(cur);
        }
        return ans;
        
    }
};