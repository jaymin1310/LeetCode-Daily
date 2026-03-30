class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1==s2)return true;
        int n=s1.size();
        vector<int>odd(26,0),even(26,0);
        for(int i=0;i<n;i++){
            if(i%2){
                odd[s1[i]-'a']++;
                odd[s2[i]-'a']--;
            }else{
                even[s1[i]-'a']++;
                even[s2[i]-'a']--;
            }
        }
        return odd==vector<int>(26,0) && even==vector<int>(26,0);
    }
};