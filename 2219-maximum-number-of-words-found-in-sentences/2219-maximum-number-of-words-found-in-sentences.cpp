#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int mostWordsFound(std::vector<std::string>& sentences) {
        int maxWords = 0;
        for (const auto& sentence : sentences) {
            int wordCount = std::count(sentence.begin(), sentence.end(), ' ') + 1;
            maxWords = std::max(maxWords, wordCount);
        }
        return maxWords;
    }
};
