class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int x : nums) mp[x]++;

        // Bucket array: index = frequency
        vector<vector<int>> bucket(nums.size() + 1);

        // Fill buckets
        for (auto &p : mp) {
            int val = p.first;
            int freq = p.second;
            bucket[freq].push_back(val);
        }

        vector<int> res;

        // Traverse from highest frequency to lowest
        for (int freq = nums.size(); freq >= 1 && res.size() < k; freq--) {
            for (int val : bucket[freq]) {
                res.push_back(val);
                if (res.size() == k) break;
            }
        }

        return res;
    }
};
