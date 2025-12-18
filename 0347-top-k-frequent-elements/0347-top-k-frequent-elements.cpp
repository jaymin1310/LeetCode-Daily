class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        auto it=mp.begin();
        for(int i=0;i<k;i++){
            pq.push({it->second,it->first});
            it++;
        }
        for(;it!=mp.end();it++){
            if(it->second>pq.top().first){
                pq.pop();
                pq.push({it->second,it->first});
            }
        }
        vector<int>res;
        while(!pq.empty()){
            auto it=pq.top();
            res.push_back(it.second);
            pq.pop();
        }
        return res;
    }
};