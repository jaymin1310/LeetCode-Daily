class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        int ind=-1;
        int n=num.size();
        for(int i=0;i<n;i++){
            int digit=num[i]-'0';
            while(!st.empty()&& digit<(st.back()-'0') && k!=0){
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
            if(k==0){
                ind=i;
                break;
            }
        }
        if(ind!=-1){
            for(int i=ind+1;i<n;i++){
                st.push_back(num[i]);
            }
        }else{
            st.erase(st.size()-k);
        }
        while(!st.empty() && st[0]=='0'){
            st.erase(0, 1);
        }
        if(st.empty())return "0";
        return st;
    }
};