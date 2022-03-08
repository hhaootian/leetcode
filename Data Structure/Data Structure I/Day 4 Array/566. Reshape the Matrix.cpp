class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (r * c != mat.size() * mat[0].size())
            return mat;

        vector<vector<int>> ans;
        int mat_i = 0, mat_j = 0;
        for (int i = 0; i < r; i++) {
            vector<int> cur;
            for (int j = 0; j < c; j++) {
                if (mat_j == mat[0].size()) {
                    mat_i++;
                    mat_j = 0;
                }
                cur.push_back(mat[mat_i][mat_j]);
                mat_j++;
            }
            ans.push_back(cur);
        }
        return ans;
    }
};