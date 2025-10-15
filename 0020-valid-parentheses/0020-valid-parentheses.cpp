class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s){
            if(it=='(' || it=='{' || it=='['){
                st.push(it);
            }else{
                if(st.empty())return false;
                char top=st.top();
                if(top=='('&& it==')' ||top=='{'&& it=='}' || top=='['&& it==']'){
                    st.pop();
                    continue;
                }
                return false;
            }
        }
        if(st.empty())return true;
        return false;
    }
};