class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> Row, Col, Box;

            for (int j = 0; j < 9; ++j) {
                char rowVal = board[i][j];
                char colVal = board[j][i];
                char boxVal = board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3];

                if (rowVal != '.' && Row.count(rowVal)) return false;
                if (colVal != '.' && Col.count(colVal)) return false;
                if (boxVal != '.' && Box.count(boxVal)) return false;

                if (rowVal != '.') Row.insert(rowVal);
                if (colVal != '.') Col.insert(colVal);
                if (boxVal != '.') Box.insert(boxVal);
            }
        }

        return true;
    }
};