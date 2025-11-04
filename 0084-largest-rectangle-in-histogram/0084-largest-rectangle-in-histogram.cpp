class Solution {
public:
    vector<int> NSE(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty())ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> PSE(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty())ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nse=NSE(heights);
        vector<int>pse=PSE(heights);
        int n=heights.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int freq=nse[i]-pse[i]-1;
            ans=max(ans,heights[i]*freq);
        }
        return ans;
    }
};