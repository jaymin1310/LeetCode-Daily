class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>qu;
        vector<int>ans;
        for(int i=0;i<n;i++){
            while(!qu.empty() && nums[i]>=nums[qu.back()]){
                qu.pop_back();
            }
            qu.push_back(i);
            if(qu.front()<=i-k){
                qu.pop_front();
            }
            if(i>=k-1){
                ans.push_back(nums[qu.front()]);
            }
        }
        return ans;
    }
};