class Solution {
public:
    static const int MOD=26;
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto &it:words){
            int sum=0;
            for(auto &chara:it){
                sum+=weights[chara-'a'];
            }
            sum%=MOD;
            ans.push_back(25-sum+'a');
        }
        return ans;
    }
};