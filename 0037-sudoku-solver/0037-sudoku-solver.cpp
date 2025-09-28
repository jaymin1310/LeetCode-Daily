class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int curRow, int curCol, int num,
                vector<vector<int>>& row, vector<vector<int>>& col,
                vector<vector<int>>& subBox) {
        int boxR = (curRow / 3) * 3 + (curCol / 3);
        return !(row[curRow][num] || col[curCol][num] || subBox[boxR][num]);
    }
    bool recursion(vector<vector<char>>& board, int curRow, int curCol,
                   vector<vector<int>>& row, vector<vector<int>>& col,
                   vector<vector<int>>& subBox) {
        if (curCol == 9) {
            curRow++;
            curCol = 0;
        }
        if (curRow == 9)
            return true;
        if (board[curRow][curCol] == '.') {
            for (int num = 1; num <= 9; num++) {
                if (isSafe(board, curRow, curCol, num, row, col, subBox)) {
                    int boxR = (curRow / 3) * 3 + (curCol / 3);
                    board[curRow][curCol] = num + '0';
                    row[curRow][num] = col[curCol][num] = subBox[boxR][num] = 1;
                    if (recursion(board, curRow, curCol + 1, row, col, subBox))
                        return true;
                    board[curRow][curCol] = '.';
                    row[curRow][num] = col[curCol][num] = subBox[boxR][num] = 0;
                }
            }
            return false;
        } else {
            return recursion(board, curRow, curCol + 1, row, col, subBox);
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(10, 0));
        vector<vector<int>> col(9, vector<int>(10, 0));
        vector<vector<int>> subBox(9, vector<int>(10, 0));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row[i][num] = 1;
                    col[j][num] = 1;
                    int boxR = (i / 3) * 3 + (j / 3);
                    subBox[boxR][num] = 1;
                }
            }
        }
        recursion(board, 0, 0, row, col, subBox);
    }
};
