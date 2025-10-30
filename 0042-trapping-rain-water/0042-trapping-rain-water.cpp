class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int n=height.size();
        vector<int>ans(n,-1);
         for(int i=n-1;i>=0;i--){
            int ind=-1;
            while(!st.empty() && height[i]>height[st.top()]){
                ind=st.top();
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
                if(height[st.top()]==height[i]){
                    st.pop();
                }
            }else{
                ans[i]=ind;
            }
            st.push(i);
        }
        int low,high,i=0;
        int res=0;
        while(i<n){
            if(ans[i]==-1 || ans[i]==i+1){
                i++;
            }else{
                low=i+1;
                high=ans[i];
                int mini=min(height[i],height[ans[i]]);
                for(int j=low;j<high;j++){
                    res+=mini-height[j];
                }
                i=high;
            }
        }
        return res;
    }
};