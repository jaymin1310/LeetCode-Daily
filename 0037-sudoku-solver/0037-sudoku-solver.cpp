class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int curRow, int curCol, int num,
                vector<vector<int>>& row, vector<vector<int>>& col,
                vector<vector<int>>& subBox) {
                    int boxR = (curCol / 3) + (3 * (curRow / 3));
                    if(row[curRow][num]==1 || col[curCol][num]==1 || subBox[boxR][num]==1){
                        return false;
                    }
                    return true;
                }
    bool recursion(vector<vector<char>>& board, int curRow, int curCol,
                   vector<vector<int>>& row, vector<vector<int>>& col,
                   vector<vector<int>>& subBox) {
        if (curCol == 0) {
            curRow += 1;
        }
        if (curRow == 9) {
            return true;
        }
        if (board[curRow][curCol] == '.') {
            for (int num = 1; num <= 9; num++) {
                if (isSafe(board, curRow, curCol, num, row, col, subBox)) {
                    board[curRow][curCol] = num + '0';
                    row[curRow][num]=1;
                    col[curCol][num]=1;
                    int boxR = (curCol / 3) + (3 * (curRow / 3));
                    subBox[boxR][num]=1;
                    if (recursion(board, curRow, (curCol + 1) % 9, row, col,
                                  subBox))
                        return true;
                    board[curRow][curCol] = '.';
                    row[curRow][num]=0;
                    col[curCol][num]=0;
                    subBox[boxR][num]=0;
                }
            }
            return false;
        } else {
            return recursion(board, curRow, (curCol + 1) % 9, row, col, subBox);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(10, 0));
        vector<vector<int>> col(9, vector<int>(10, 0));
        vector<vector<int>> subBox(9, vector<int>(10, 0));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    row[i][board[i][j] - '0'] = 1;
                    col[j][board[i][j] - '0'] = 1;
                    int boxR = (j / 3) + (3 * (i / 3));
                    subBox[boxR][board[i][j] - '0'] = 1;
                }
            }
        }
        recursion(board, -1, 0, row, col, subBox);
    }
};