class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        // choose random pivot and move to right
        int pivotIndex = left + rand() % (right - left + 1);
        swap(nums[pivotIndex], nums[right]);
        
        int pivot = nums[right];
        int store = left;

        // Partition so that greater elements come first
        for (int i = left; i < right; i++) {
            if (nums[i] > pivot) {  // for kth largest
                swap(nums[i], nums[store]);
                store++;
            }
        }

        swap(nums[store], nums[right]);
        return store;
    }

    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];

        int pivotIndex = partition(nums, left, right);
        
        if (pivotIndex == k)
            return nums[pivotIndex];
        else if (pivotIndex < k)
            return quickSelect(nums, pivotIndex + 1, right, k);
        else
            return quickSelect(nums, left, pivotIndex - 1, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));  
        int n = nums.size();
        int index = k - 1;   // we want kth largest = index k-1 in descending order
        return quickSelect(nums, 0, n - 1, index);
    }
};
