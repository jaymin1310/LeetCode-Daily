class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size();
        int newintStart = -1, newintLast = -1;
        int i = 0;
        vector<vector<int>> res;
        while (i < n && intervals[i][0] < newInterval[0]) {
            res.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        if (i >= n && !res.empty() && res.back()[1] < newInterval[0]) {
            res.push_back({newInterval[0], newInterval[1]});
            return res;
        }
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
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newintLast = max(newintLast, intervals[i][1]);
            i++;
        }
        res.push_back({newintStart, newintLast});
        while (i < n) {
            res.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        return res;
    }
};