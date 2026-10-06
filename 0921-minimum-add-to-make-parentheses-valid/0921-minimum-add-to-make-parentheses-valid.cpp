class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0,ans=0;
        for(auto &it:s){
            if(it=='('){
                if(cnt<0){
                    ans+=abs(cnt);
                    cnt=1;
                }
                else cnt++;

            }else{
                cnt--;
            }
        }
        ans+=abs(cnt);
        return ans;
    }
};