class Solution {
public:
    int cntbeauty(string&s,int start,int end){
        vector<int>arr(26,0);
        int mincnt=INT_MAX,maxcnt=INT_MIN;
        for(int i=start;i<=end;i++){
            arr[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=0){
                mincnt=min(arr[i],mincnt);
                maxcnt=max(arr[i],maxcnt);
            }
        }
        return maxcnt-mincnt;
    }
    int beautySum(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int res=cntbeauty(s,i,j);
                ans+=res;
            }
        }
        return ans;
    }
};