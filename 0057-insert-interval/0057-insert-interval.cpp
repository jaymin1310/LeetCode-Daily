class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size();
        int newintStart = -1, newintLast = -1;
        int i = 0;
        vector<vector<int>> res;

        // Add intervals that come before newInterval
        while (i < n && intervals[i][0] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        // Case: newInterval goes after all and no overlap
        if (i >= n && !res.empty() && res.back()[1] < newInterval[0]) {
            res.push_back(newInterval);
            return res;
        }

        // Merge with last interval in res if needed
        if (!res.empty()) {
            int lastStart = res.back()[0];
            int lastEnd = res.back()[1];
            if (lastEnd >= newInterval[0]) {
                res.pop_back();
                newintStart = min(lastStart, newInterval[0]);
                newintLast = max(lastEnd, newInterval[1]);
            } else {
                newintStart = newInterval[0];
                newintLast = newInterval[1];
            }
        } else {
            newintStart = newInterval[0];
            newintLast = newInterval[1];
        }

        // FIXED: merge overlapping intervals
        while (i < n && intervals[i][0] <= newintLast) {
            newintLast = max(newintLast, intervals[i][1]);
            i++;
        }

        res.push_back({newintStart, newintLast});

        // Push remaining intervals
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
