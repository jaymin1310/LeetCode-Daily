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
};