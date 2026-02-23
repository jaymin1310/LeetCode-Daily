class Solution {
public:
    void helper(stack<pair<int, int>>& st, vector<vector<int>>& vis,
                vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        while (!st.empty()) {
            auto [row, col] = st.top();
            st.pop();
            if (row + 1 < m && board[row + 1][col] == 'O' &&
                !vis[row + 1][col]) {
                vis[row + 1][col] = 1;
                st.push({row + 1, col});
            }
            if (row - 1 >= 0 && board[row - 1][col] == 'O' &&
                !vis[row - 1][col]) {
                vis[row - 1][col] = 1;
                st.push({row - 1, col});
            }
            if (col + 1 < n && board[row][col + 1] == 'O' &&
                !vis[row][col + 1]) {
                vis[row][col + 1] = 1;
                st.push({row, col + 1});
            }
            if (col - 1 >=0 && board[row][col - 1] == 'O' &&
                !vis[row][col - 1]) {
                vis[row][col - 1] = 1;
                st.push({row, col - 1});
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O' && !vis[0][i]) {
                stack<pair<int, int>> st;
                st.push({0, i});
                vis[0][i] = 1;
                helper(st, vis, board);
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                stack<pair<int, int>> st;
                st.push({i, 0});
                vis[i][0] = 1;
                helper(st, vis, board);
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[m - 1][i] == 'O' && !vis[m - 1][i]) {
                stack<pair<int, int>> st;
                st.push({m - 1, i});
                vis[m - 1][i] = 1;
                helper(st, vis, board);
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][n - 1] == 'O' && !vis[i][n - 1]) {
                stack<pair<int, int>> st;
                st.push({i, n - 1});
                vis[i][n - 1] = 1;
                helper(st, vis, board);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};