class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        int maxFreq = 0;
        for (const auto& pair : freqMap) {
            maxFreq = max(maxFreq, pair.second);
        }

        // Bucket sort: buckets[i] = list of chars with frequency i
        vector<vector<char>> buckets(maxFreq + 1);
        for (const auto& pair : freqMap) {
            buckets[pair.second].push_back(pair.first);
        }

        string result;
        for (int i = maxFreq; i > 0; --i) {
            for (char c : buckets[i]) {
                result.append(i, c); // Append 'i' copies of 'c'
            }
        }

        return result;
    }
};