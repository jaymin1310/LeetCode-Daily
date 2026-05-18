class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        vector<int>vis(n,0);
        queue<int>qu;
        qu.push(0);
        vis[0]=1;
        int cnt=0;
        while(!qu.empty()){
            int size=qu.size();
            while(size--){
                int front=qu.front();
                qu.pop();
                if(front==n-1)return cnt;
                if(front+1<n && !vis[front+1] ){
                    qu.push(front+1);
                    vis[front+1]=1;
                }
                if((front-1)>=0 && !vis[front-1]){
                    qu.push(front-1);
                    vis[front-1]=1;
                }
                if (mp.count(arr[front])) {
                    for (int nextIdx : mp[arr[front]]) {
                        if (!vis[nextIdx]) {
                            qu.push(nextIdx);
                            vis[nextIdx] = 1;
                        }
                    }
                    mp.erase(arr[front]);
                }
            }
            cnt++;
        }
        return -1;
    }
};