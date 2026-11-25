class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size(),r=n-1;
        for(int i=0;i<n/2;i++,r--){
            swap(s[i],s[r]);
        }
    }
};