class Solution {
public:
    int distance(vector<int> p1, vector<int> p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min_idx = -1;
        int min_dist = INT_MAX;
        for (int i = 0; i < points.size(); i++) {
            vector<int> point = points[i];
            if (point[0] == x || point[1] == y) {
                int dist = distance(point, {x, y});
                if (dist < min_dist) {
                    min_dist = dist;
                    min_idx = i;
                }
            }
        }

        return min_idx;
    }
};