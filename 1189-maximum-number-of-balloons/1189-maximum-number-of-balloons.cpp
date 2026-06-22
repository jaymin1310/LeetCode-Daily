class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> charMap = {
            {'b', 0}, {'a', 0}, {'l', 0}, {'o', 0}, {'n', 0}};
        for (auto& it : text) {
            if (it == 'b' || it == 'a' || it == 'l' || it == 'o' || it == 'n') {
                charMap[it]++;
            }
        }
        charMap['l']/=2;
        charMap['o']/=2;
        int cnt=INT_MAX;
        for(auto it:charMap){
            cnt=min(cnt,it.second);
        }
        return cnt==INT_MAX?0:cnt;
    }
};