class Solution {
    public int countBinarySubstrings(String s) {
        int n =s.length();
        int res=0,prev=0,strk=1;
        for(int j=1;j<n;j++){
            if(s.charAt(j) == s.charAt(j - 1))strk++;
            else{
                prev=strk;
                strk=1;
            }
            if(strk<=prev)res++;
        }
        return res;
    }
}