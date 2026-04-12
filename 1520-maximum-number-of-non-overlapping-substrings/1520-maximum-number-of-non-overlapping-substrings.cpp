class Solution {
public:
    void finishtime(int u,stack<int>&st,vector<unordered_set<int>>&adj,vector<int>&vis){
        vis[u]=1;
        for(auto &it:adj[u]){
            if(!vis[it]){
                finishtime(it,st,adj,vis);
            }
        }
        st.push(u);
    }
    void dfs(int u,vector<int>&comp,vector<unordered_set<int>>&adj,int ind){
        comp[u]=ind;
        for(auto &it:adj[u]){
            if(comp[it]==-1){
                dfs(it,comp,adj,ind);
            }
        }
    }
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        for(int i=0;i<n;i++){
            int temp=s[i]-'a';
            if(first[temp]==-1){
                first[temp]=i;
            }
            last[temp]=i;
        }
        vector<unordered_set<int>>adj(26);
        vector<unordered_set<int>>rev(26);
        for(int i=0;i<26;i++){
            if(first[i]==-1)continue;
            for(int j=first[i];j<=last[i];j++){
                int x=s[j]-'a';
                if(x!=i){
                    adj[i].insert(x);
                    rev[x].insert(i);
                }
            }
        }
        vector<int>vis(26,0);
        stack<int>st;
        for(int i=0;i<26;i++){
            if(first[i]!=-1 && !vis[i]){
                finishtime(i,st,adj,vis);
            }
        }
        vector<int>comp(26,-1);
        int ind=0;
        while(!st.empty()){
            int top=st.top();
            st.pop();
            if(comp[top]==-1){
                dfs(top,comp,rev,ind);
                ind++;
            }
        }
        vector<int>outdeg(ind,0);
        for(int i=0;i<26;i++){
            for(auto &it:adj[i]){
                if(comp[it]!=comp[i]){
                    outdeg[comp[i]]++;
                }
            }
        }
        vector<pair<int,int>> range(ind, {1e9, -1});
        for(int i=0;i<26;i++){
            if(first[i] == -1) continue;
            int ind=comp[i];
            range[ind].first=min(range[ind].first,first[i]);
            range[ind].second=max(range[ind].second,last[i]);
        }
        vector<string>ans;
        for(int i=0;i<ind;i++){
            if(outdeg[i]==0 && range[i].second!=-1){
                ans.push_back(s.substr(range[i].first,range[i].second-range[i].first+1));
            }
        }
        return ans;
    }
};