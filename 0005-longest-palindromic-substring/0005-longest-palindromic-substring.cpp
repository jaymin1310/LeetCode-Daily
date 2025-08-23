class Solution {
public:
    int expand(string &s,int mid,int mid2){
        int left=mid-1,right=mid2+1;
        if(s[mid]!=s[mid2])return -2;
        while(left>=0 && right<s.size()){
            if(s[left]!=s[right])break;
            left--;
            right++;
        }
    return left;
    }
    string longestPalindrome(string s) {
        int n=s.size(),cnt=-1,low,high;
        for(int i=0;i<n;i++){
           int res1=i-(expand(s,i,i)+1);
           int temp=expand(s,i,i+1),res2=-1;
           if(i!=n-1 && temp!=-2) res2=i-(temp+1);
           if(res2>=res1){
            if(res2>=cnt){
                cnt=res2;
                low=i-res2;
                high=res2+i+1;
            }
           }
           else{
            if(res1>cnt){
                cnt=res1;
                low=i-res1;
                high=i+res1;
            }
           }

        }
        return s.substr(low,high-low+1);
    }
};