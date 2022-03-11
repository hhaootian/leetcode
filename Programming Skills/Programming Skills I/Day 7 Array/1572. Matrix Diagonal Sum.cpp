class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int size = mat.size();
        int ans = 0;
        for (int i = 0; i < size; i++) {
            ans += mat[i][i];
            ans += mat[i][size - i - 1];
        }
        if (size % 2)
            ans -= mat[size / 2][size / 2];
        return ans;
    }
};