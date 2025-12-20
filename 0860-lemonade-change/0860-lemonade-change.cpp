class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        for (int b : bills) {
            if (b == 5) {
                mp[5]++;
                continue;
            }

            if (b == 10) {
                if (mp[5] == 0) return false;
                mp[5]--;
                mp[10]++;
            }

            else { // b == 20
                if (mp[10] > 0 && mp[5] > 0) {
                    mp[10]--;
                    mp[5]--;
                } 
                else if (mp[5] >= 3) {
                    mp[5] -= 3;
                } 
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
