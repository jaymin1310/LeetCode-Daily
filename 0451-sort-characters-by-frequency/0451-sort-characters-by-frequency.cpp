#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256, 0);
        for (unsigned char c : s) {
            freq[c]++;
        }
        vector<pair<char,int>> freqPairs;
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                freqPairs.push_back({(char)i, freq[i]});
            }
        }
        sort(freqPairs.begin(), freqPairs.end(),
             [](auto &a, auto &b) {
                 return a.second > b.second;
             });
        string result;
        for (auto &p : freqPairs) {
            result.append(p.second, p.first); 
        }

        return result;
    }
};
