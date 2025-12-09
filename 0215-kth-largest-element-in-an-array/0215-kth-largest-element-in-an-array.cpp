class Solution {
public:
    int findIndex(vector<int>& nums, int start, int end) {
        int pivot = nums[start];
        int low = start + 1;
        int high = end;
        while (low <= high) {
            while (low <= high && nums[low] > pivot)
                low++;
            while (low <= high && nums[high] <= pivot)
                high--;
            if (low < high) {
                swap(nums[low], nums[high]);
            }
        }
        swap(nums[start], nums[high]);
        return high;
    }
    int partation(vector<int>& nums, int start, int end, int k) {
        int pind = findIndex(nums, start, end);
        if (pind + 1 == k)
            return nums[pind];
        else if (pind >= k) {
            end = pind - 1;
        } else {
            start = pind + 1;
        }
        return partation(nums, start, end, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return partation(nums, 0, nums.size() - 1, k);
    }
};