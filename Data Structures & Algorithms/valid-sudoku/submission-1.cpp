class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0), cols(9, 0), boxes(9, 0);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;

                int bit = 1 << (c - '1'); // one bit per digit
                int b = (i / 3) * 3 + (j / 3);

                if ((rows[i] & bit) || (cols[j] & bit) || (boxes[b] & bit)) {
                    return false;
                }

                rows[i]  |= bit;
                cols[j]  |= bit;
                boxes[b] |= bit;
            }
        }
        return true;
    }
};
