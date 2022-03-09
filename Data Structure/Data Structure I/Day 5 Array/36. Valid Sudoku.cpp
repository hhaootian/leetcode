class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {0};
        bool col[9][9] = {0};
        bool box[9][9] = {0};

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0' - 1;
                if (row[i][num])
                    return false; 
                if (col[j][num])
                    return false;
                if (box[j / 3 + (i / 3) * 3][num])
                    return false;

                row[i][num] = true;
                col[j][num] = true;
                box[j / 3 + (i / 3) * 3][num] = true;
            }
        }
        return true;
    }
};