class Solution {
public:
    long long findhour(int ban, const vector<int>& arr, int n){
        long long total = 0;
        for(int i = 0; i < n; i++){
            total += (arr[i] + ban - 1) / ban; // integer ceil
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int mxbn = *max_element(piles.begin(), piles.end());
        int low = 1, high = mxbn, ans = mxbn;

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long result = findhour(mid, piles, n);

            if(result <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};
