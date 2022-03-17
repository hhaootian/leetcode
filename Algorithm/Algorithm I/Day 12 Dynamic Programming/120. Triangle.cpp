class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); i++) {
            int size = triangle[i - 1].size();
            triangle[i][0] += triangle[i - 1][0];
            for (int j = 1; j < size; j++)
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i-1][j]);
            triangle[i][size] += triangle[i-1][size - 1];
        }
        return *min_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
    }
};