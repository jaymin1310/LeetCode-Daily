class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        int res=0;
        vector<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.back()]>arr[i]){
                int temp=arr[st.back()];
                st.pop_back();
                int freq=(i-1)-((!st.empty())?st.back():-1);
                int value=freq*temp;
                res=max(res,value);
            }
            st.push_back(i);
        }
        while(!st.empty()){
            int temp=arr[st.back()];
            st.pop_back();
            int freq=(n-1)-((!st.empty())?st.back():-1);
            int value=freq*temp;
            res=max(res,value);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int res=0;
        vector<vector<int>>temp(row,vector<int>(col));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0){
                    temp[i][j]=matrix[i][j]-'0';
                }else{
                    if(matrix[i][j]=='0'){
                        temp[i][j]=0;
                    }else{
                        temp[i][j] = (matrix[i][j] - '0') + temp[i-1][j] ;
                    } 
                }
            }
            res=max(res,largestRectangleArea(temp[i]));
        }
        return res;
    }
};