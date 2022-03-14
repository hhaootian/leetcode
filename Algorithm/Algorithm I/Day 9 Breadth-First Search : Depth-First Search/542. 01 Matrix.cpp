class Solution {
public:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    que.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int value = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                int x = que.front().first, y = que.front().second;
                que.pop();
                mat[x][y] = value;

                for (int d = 0; d < 4; d++) {
                    int newx = x + dx[d], newy = y + dy[d];
                    if (newx >= 0 && newx < m && newy >= 0 && newy < n && !visited[newx][newy]) {
                        que.push({newx, newy});
                        visited[newx][newy] = true;
                    }
                }
            }
            value ++;
        }
        return mat;
    }
};