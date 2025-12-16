class KthLargest {
    priority_queue<int,vector<int>,greater<int>>pq;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K=k;
        int n=nums.size();
        for(int i=0;i<k && i<n;i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<n;i++){
            int top=pq.top();
            if(nums[i]>top){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(pq.empty() || pq.size()<K){
            pq.push(val);
        }else{
            int top=pq.top();
            if(val>top){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */