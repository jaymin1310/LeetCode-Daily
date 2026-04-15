class Solution {
public:
    int closestTarget(vector<string>& words, string target, int start) {
        int ans=INT_MAX,n=words.size();
        if(target==words[start])return 0;
        int ind=(start+1)%n;
        while(ind!=start){
            if(words[ind]==target){
                int dist = abs(ind - start);
                ans = min(ans, min(dist, n - dist));
            }
            ind=(ind+1)%n;
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};