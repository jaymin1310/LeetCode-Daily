class Solution {
    public int characterReplacement(String s, int k) {
        int n=s.length();
        int l=0,r=0;
        int len=0,maxFre=0;
        int[] freq=new int[26];
        while(r<n){
            freq[s.charAt(r)-'A']++;
            maxFre=Math.max(maxFre,freq[s.charAt(r)-'A']);
            if((r-l+1-maxFre)>k){
                freq[s.charAt(l)-'A']--;
                l++;
            }
            len=Math.max(len,r-l+1);
            r++;
        }
        return len;
    }
}