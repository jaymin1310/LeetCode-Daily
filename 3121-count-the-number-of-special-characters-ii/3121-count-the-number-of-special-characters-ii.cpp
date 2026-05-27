class Solution {
public:
    int numberOfSpecialChars(string word) {
        int low=0,up=0,cnt=0;
        for(auto & it:word){
            if(isupper(it)){
                up|=1<<(it-'A');
            }else{
                low|=1<<(it-'a');
                if((up & 1<<(it-'a') )){
                    low&=~(1<<(it-'a'));
                }
            }
        }
        int finalBit=low&up;
        for(int i=0;i<26;i++){
            if(finalBit & 1<<i)cnt++;
        }
        return cnt;
    }
};