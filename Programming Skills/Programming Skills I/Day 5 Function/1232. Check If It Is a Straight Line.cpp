class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int size = coordinates.size();
        for(int i = 1; i < size - 1; i++) {
            if (
                (coordinates[i][0] - coordinates[0][0])*
                (coordinates[i][1] - coordinates[size - 1][1])
                !=
                (coordinates[i][1] - coordinates[0][1])*
                (coordinates[i][0] - coordinates[size - 1][0])
            )
                return false;
        }
        return true;
    }
};