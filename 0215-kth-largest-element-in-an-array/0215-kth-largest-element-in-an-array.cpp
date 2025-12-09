class Solution {
public:
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    void heapify(vector<int>&nums,int i){
        int li=left(i);
        int ri=right(i);
        int maxi=i,n=nums.size();
        if(li<n && nums[li]>nums[maxi]){
            maxi=li;
        }
        if(ri<n && nums[ri]>nums[maxi]){
            maxi=ri;
        }
        if(maxi!=i){
            swap(nums[maxi],nums[i]);
            heapify(nums,maxi);
        }
    }
    int extractMax(int k,vector<int>&nums){
        if(k==1)return nums[0];
        nums[0]=nums[nums.size()-1];
        nums.pop_back();
        if(nums.size()>0){
            heapify(nums,0);
        }
        return extractMax(k-1,nums);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int nLNode=(nums.size()/2)-1;
        for(int i=nLNode;i>=0;i--){
            heapify(nums,i);
        }
        return extractMax(k,nums);
    }
};