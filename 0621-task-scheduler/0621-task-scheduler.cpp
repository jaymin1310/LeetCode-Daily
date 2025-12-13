class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
          vector<int>freq(26,0);
          for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
          }
          priority_queue<pair<int,int>>pq;
          for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push({freq[i],i});
            }
          }
          int ans=0;
          queue<pair<int,int>>cool;
        while(true){
            int tot=pq.size();
            int cnt=0;
            while(!pq.empty() && cnt<n+1){
                auto it=pq.top();
                pq.pop();
                it.first--;
                if(it.first>0)cool.push(it);
                cnt++;
            }
            if(cool.empty()){
                ans+=tot;
                break;
            }
            ans+=n+1;
            while(!cool.empty()){
                pq.push(cool.front());
                cool.pop();
            }
        }
        return ans;
    }
};