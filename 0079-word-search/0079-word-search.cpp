class Solution {
public:
    int row;
    int col;
    bool recursion(vector<vector<char>>& board, string& word, int i, int j,
                   int ind) {
        if (ind == word.size())
            return true;
        char original = board[i][j];
        board[i][j] = '#';
        char temp = word[ind];

        bool found =
            (i < row && col > j + 1 && board[i][j + 1] == temp &&
             recursion(board, word, i, j + 1, ind + 1)) || // right
            (j > 0 && i < row && col > j - 1 && board[i][j - 1] == temp &&
             recursion(board, word, i, j - 1, ind + 1)) || // left
            (i > 0 && i - 1 < row && col > j && board[i - 1][j] == temp &&
             recursion(board, word, i - 1, j, ind + 1)) || // up
            (i + 1 < row && col > j && board[i + 1][j] == temp &&
             recursion(board, word, i + 1, j, ind + 1)); // down
        board[i][j] = original;
        if (found)
            return true;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        row = r;
        col = c;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    if (recursion(board, word, i, j, 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};