class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        st.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]==')'){
                if(s[i]=='(')st.push(0);
                else{
                    if(st.top()!=0)return false;
                    st.pop();
                }
            }else if(s[i]==']' || s[i]=='['){
                if(s[i]=='[')st.push(1);
                else{
                    if(st.top()!=1)return false;
                    st.pop();
                }
            }else{
                if(s[i]=='{')st.push(2);
                else{
                    if(st.top()!=2)return false;
                    st.pop();
                }
            }
        }
        if(st.top()!=-1)return false;
        return true;
    }
};