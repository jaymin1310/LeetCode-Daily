class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int>qu;
        vector<int>vis(n,0);
        qu.push(start);
        while(!qu.empty()){
            int top=qu.front();
            if(!arr[top])return true;
            qu.pop();
            int right=top+arr[top];
            if(right<n && !vis[right]){
                qu.push(right);
                vis[right]=1;
            }
            int left=top-arr[top];
            if(left>=0 && !vis[left]){
                qu.push(left);
                vis[left]=1;
            }
        }
        return false;
    }
};