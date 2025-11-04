class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        int res=0;
        vector<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.back()]>arr[i]){
                int pInd=st.size()-2;
                int freq=(i-1)-((pInd)>=0?st[pInd]:-1);
                int value=freq*arr[st.back()];
                res=max(res,value);
                st.pop_back();
            }
            st.push_back(i);
        }
        while(!st.empty()){
            int pInd=st.size()-2;
            int freq=(n-1)-((pInd)>=0?st[pInd]:-1);
            int value=freq*arr[st.back()];
            res=max(res,value);
            st.pop_back();
        }
        return res;
    }
};