class Solution {
    public int characterReplacement(String s, int k) {
        int n=s.length();
        int l=0,r=0;
        int[] freq=new int[26];
        int len=0;
        while(r<n){
            freq[s.charAt(r)-'A']++;
            int maxFre=0;
            for(int i=0;i<26;i++){
                maxFre=Math.max(maxFre,freq[i]);
            }
            if((r-l+1-maxFre)>k){
                freq[s.charAt(l)-'A']--;
                l++;
            }else{
                len++;
            }
            r++;
        }
        return len;
    }
}