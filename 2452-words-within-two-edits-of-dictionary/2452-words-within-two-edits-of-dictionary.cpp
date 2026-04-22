class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(auto &it:queries){
            for(auto &dic:dictionary){
                int edit=0;
                for(int i=0;i<it.length();i++){
                    if(it[i]!=dic[i])edit++;
                    if(edit>2)break;
                }
                if(edit<=2){
                    ans.push_back(it);
                    break;
                }
            }
            
        }
        return ans;
    }
};