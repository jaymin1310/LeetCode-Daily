class Solution {
public:
    void dfs(unordered_map<string, int>& mp, vector<vector<string>>& ans,
             vector<string>& temp) {
        string last = temp.back();
        if (mp[last] == 0) {
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            reverse(temp.begin(), temp.end());
            return;
        }
        string word = last;
        for (int ind = 0; ind < last.size(); ind++) {
            char org = word[ind];
            for (int i = 0; i < 26; i++) {
                word[ind] = i + 'a';
                if (mp.find(word) != mp.end() && mp[last] == mp[word] + 1) {
                    temp.push_back(word);
                    dfs(mp, ans, temp);
                    temp.pop_back();
                }
            }
            word[ind] = org;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        int n = wordList.size();
        unordered_set<string> st;
        unordered_map<string, int> mp;
        for (auto it : wordList) {
            st.insert(it);
        }
        queue<string> qu;
        vector<vector<string>> ans;
        qu.push(beginWord);
        int flag = 0, lvl = 0;
        if (st.find(endWord) == st.end())
            return {};
        if (st.find(beginWord) != st.end())
            st.erase(beginWord);
        while (!qu.empty()) {
            int size = qu.size();
            while (size--) {
                string word = qu.front();
                mp[word] = lvl;
                qu.pop();
                if (word == endWord) {
                    flag = 1;
                    continue;
                }
                for (int ind = 0; ind < word.size(); ind++) {
                    char org = word[ind];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[ind] = ch;
                        if (st.find(word) != st.end()) {
                            qu.push(word);
                            st.erase(word);
                        }
                    }
                    word[ind] = org;
                }
            }
            if (flag == 1)
                break;
            lvl++;
        }
        if (flag == 0)
            return ans;
        vector<string> path;
        path.push_back(endWord);
        dfs(mp, ans, path);
        return ans;
    }
};