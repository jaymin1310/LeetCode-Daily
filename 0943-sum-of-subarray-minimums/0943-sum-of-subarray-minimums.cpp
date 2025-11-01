class Solution {
public:
    //NSE
     vector<int> nextSE(vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        vector<int>res(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                res[i]=st.top();
            }
            st.push(i);
        }
        return res;
    }
    //PSEE
    vector<int> previousSE(vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        vector<int>res(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] >arr[i]){
                st.pop();
            }
            if(!st.empty()){
                res[i]=st.top();
            }
            st.push(i);
        }
        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long res=0;
        int MOD=1e9+7;
        vector<int>pse=previousSE(arr);
        vector<int>nse=nextSE(arr);
        int left,right;
        for(int i=0;i<n;i++){
            left=i-pse[i];
            right=nse[i]-i;
            long long Tot=1LL*left*right*arr[i];
            res+=Tot;
        }
        return res%MOD;
    }
};