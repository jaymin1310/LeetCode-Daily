class Solution {
public:
    vector<vector<string>> ans;
    bool isSafe(vector<vector<char>>& board, int row, int col, int n) {
        //top
        for (int i = row-1; i >= 0; i--) {
            if (board[i][col] == 'Q'){
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void recursion(int n, vector<vector<char>>& temp, int row) {
        if (row == n) {
            vector<string> vec;
            for (auto& r : temp) {
                string s(r.begin(), r.end());
                vec.push_back(s);
            }
            ans.push_back(vec);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isSafe(temp, row, i, n)) {
                temp[row][i] = 'Q';
                recursion(n, temp, row + 1);
                temp[row][i] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> temp(n, vector<char>(n, '.'));
        recursion(n, temp, 0);
        return ans;
    }
};