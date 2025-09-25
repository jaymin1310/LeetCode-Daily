class Solution {
public:
    vector<vector<string>> ans;
    void recursion(int n, vector<string>& board, int row,vector<int>&colC,vector<int>&ulC,vector<int>&urC) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (colC[i]==0 && ulC[row-i+(n-1)]==0 &&urC[row+i]==0){
                board[row][i]='Q';
                colC[i]=1;
                ulC[row-i+(n-1)]=1;
                urC[row+i]=1;
                recursion(n,board,row+1,colC,ulC,urC);
                board[row][i]='.';
                colC[i]=0;
                ulC[row-i+(n-1)]=0;
                urC[row+i]=0;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            temp[i]=s;
        }
        vector<int>colC(n,0);
        vector<int>ulC(2*n-1,0);
        vector<int>urC(2*n-1,0);
        recursion(n, temp, 0,colC,ulC,urC);
        return ans;
    }
};