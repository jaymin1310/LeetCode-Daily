class Solution {
public:
    int longestBalanced(string s) {
        int n=s.length();
        int ans=0;
        for(int k=0;k<n;k++){
            vector<int>freq(26,0);
            int dist=0,maxfreq=0;
            for(int j=k;j<n;j++){
                int ind=s[j]-'a';
                if(!freq[ind])dist++;
                freq[ind]++;
                maxfreq=max(freq[ind],maxfreq);
                int len=j-k+1;
                if(maxfreq*dist==len)
                    ans=max(ans,j-k+1);
            }
        }
        return ans;
    }
};