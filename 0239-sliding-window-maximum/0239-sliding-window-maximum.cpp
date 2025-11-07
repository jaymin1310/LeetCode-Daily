class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>qu;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(qu.empty() || nums[i]>=nums[qu.back()]){
                qu.clear();
                qu.push_back(i);
            }else{
                while(nums[qu.front()]<=nums[i]){
                    qu.pop_front();
                }
                qu.push_front(i);
            }
            if(i>=k-1){
                while(qu.back()<((i+1)-k)){
                    qu.pop_back();
                }
                ans.push_back(nums[qu.back()]);
            }
        }
        return ans;
    }
};