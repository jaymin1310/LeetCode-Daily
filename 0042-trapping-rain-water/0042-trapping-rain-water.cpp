class Solution {
public:
    int trap(vector<int>& height) {
        int right=0,left=0,total=0;
        int low=0,high=height.size()-1;
        while(low<=high){
            if(height[low]<=height[high]){
                if(left>height[low]){
                    total+=left-height[low];
                }else{
                    left=height[low];
                }
                low++;
            }else{
                if(right>height[high]){
                    total+=right-height[high];
                }else{
                    right=height[high];
                }
                high--;
            }
        }
        return total;
    }
};