class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(arr[i]>0){
                while(!st.empty() && st.top()<0 && abs(st.top())<arr[i]){
                    st.pop();
                }
                if(!st.empty()){
                    if(st.top()>0){
                        st.push(arr[i]);
                    }else if(arr[i]==abs(st.top())){
                        st.pop();
                    }
                }else{
                    st.push(arr[i]);
                }
            }else{
                st.push(arr[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};