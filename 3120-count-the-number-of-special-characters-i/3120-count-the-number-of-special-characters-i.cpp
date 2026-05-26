class Solution {
public:
    int numberOfSpecialChars(string word) {
        int small=0;
        int cap=0;
        for(auto &it:word){
            if(isupper(it)){
                int pos=it-'A';
                cap|=1<<pos;
            }else{
                int pos=it-'a';
                small|=1<<pos;
            }
        }
        int final=small&cap,cnt=0;
        for(int i=0;i<26;i++){
            if(final & (1<<i))cnt++;
        }
        return cnt;
    }
};