class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         vector<int>freq(26,0);
          int maxcnt=0;
          for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
          }
          int maxFreq = *max_element(freq.begin(), freq.end());
          for(int i=0;i<26;i++){
            if(freq[i]==maxFreq){
                maxcnt++;
            }
          }
         int ans= max((int)tasks.size(),(maxFreq - 1) * (n + 1) + maxcnt);
         return ans;
    }
};