#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a = nums[0], b = nums[1], c = nums[2];

        // Check if it forms a triangle
        if (a + b <= c) return "none";

        // Check type
        if (a == b && b == c) return "equilateral";
        if (a == b || b == c || a == c) return "isosceles";
        return "scalene";
    }
};