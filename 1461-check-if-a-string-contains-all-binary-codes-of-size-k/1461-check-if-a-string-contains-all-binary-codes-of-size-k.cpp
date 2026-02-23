class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        unordered_set<string>st;
        for(int i=0;i<=n-k;i++){
            string temp;
            for(int j=i;j<k+i;j++){
                temp+=s[j];
            }
            st.insert(temp);
        }
        return (st.size()==pow(2,k));
    }
};