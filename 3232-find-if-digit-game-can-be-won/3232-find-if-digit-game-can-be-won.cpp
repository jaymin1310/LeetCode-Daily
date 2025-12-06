#include <vector>
using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        long long sumSingle = 0;
        long long sumDouble = 0;
        for (int x : nums) {
            if (x < 10) sumSingle += x;
            else sumDouble += x;
        }
        return sumSingle != sumDouble;
    }
};
