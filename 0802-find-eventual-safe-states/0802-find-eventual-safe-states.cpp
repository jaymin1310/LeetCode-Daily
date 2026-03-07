class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>outdegree(n,0);
        vector<vector<int>>revgraph(n);
        queue<int>qu;
        for(int i=0;i<n;i++){
            outdegree[i]=graph[i].size();
            if(!outdegree[i])qu.push(i);
            for(auto &v:graph[i]){
                revgraph[v].push_back(i);
            }

        }
        vector<int>ans;
        while(!qu.empty()){
            int front=qu.front();
            qu.pop();
            ans.push_back(front);
            for(auto &parent:revgraph[front]){
                if(outdegree[parent])outdegree[parent]--;
                if(!outdegree[parent]){
                    qu.push(parent);
                }
            }
        }sort(ans.begin(),ans.end());
        return ans;
    }
};