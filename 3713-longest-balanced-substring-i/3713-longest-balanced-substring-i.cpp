class Solution {
public:
    int longestBalanced(string s) {
        int n=s.length();
        int ans=0;
        for(int k=0;k<n;k++){
            vector<int>freq(26,0);
            for(int j=k;j<n;j++){
                freq[s[j]-'a']++;
                int balance=0;
                bool valid=true;
                for(int i=0;i<26;i++){
                    if(freq[i]!=0){
                        if(!balance)balance=freq[i];
                        else if(freq[i]!=balance){
                            valid=false;
                            break;
                        }
                    }
                }
                if(valid)
                ans=max(ans,j-k+1);
            }
        }
        return ans;
    }
};