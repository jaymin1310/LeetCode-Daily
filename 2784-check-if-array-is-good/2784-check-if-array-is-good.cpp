class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return false;
        int maxVal = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
            }
        }
        vector<int>freq(maxVal+1,1);
        freq[maxVal]++;
        if(maxVal!=n-1)return false;
        for (int i = 0; i < n; i++) {
            if(!freq[nums[i]])return false;
            freq[nums[i]]--;
        }
        return true;
    }
};