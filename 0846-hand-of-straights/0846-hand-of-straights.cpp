class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groups) {
        int n=hand.size();
        if(n%groups!=0)return false;
        map<int,int>mp;
        for(int it:hand){
            mp[it]++;
        }
        for(auto it:mp){
            int start=it.first;
            while(mp[start]>0){
                for (int i = 0; i < groups; i++) {
                    int curr = start + i;
                    if (mp.find(curr) == mp.end() || mp[curr] == 0)
                        return false;
                    mp[curr]--;
                }
            }
        }
        return true;

    }
};