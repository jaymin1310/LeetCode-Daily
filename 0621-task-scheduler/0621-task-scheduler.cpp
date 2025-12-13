class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
          vector<int>freq(26,0);
          for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
          }
          priority_queue<int>pq;
          for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push(freq[i]);
            }
          }
          int tot=0;
        while(!pq.empty()){
            vector<int>temp;
            int cycle=n+1;
            while(!pq.empty() && cycle>0){
                int it=pq.top();
                pq.pop();
                tot++;
                if(it-1>0)temp.push_back(it-1);
                cycle--;
            }
            for(int t:temp){
                pq.push(t);
            }
            if(pq.empty())break;
            tot+=cycle;
        }
        return tot;
    }
};