class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(auto &it:s){
            if(it=='(' || it=='[' || it=='{'){
                st.push(it);
            }else{
                if(st.empty())return false;
                int diff=it-st.top();
                if(diff<0 || diff>2)return false;
                st.pop();
            }
        }
        return st.empty();
    }
};