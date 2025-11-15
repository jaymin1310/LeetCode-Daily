class LFUCache {
    unordered_map<int, pair<int,int>> kvf;              // key -> {value, freq}
    unordered_map<int, list<int>::iterator> mp;         // key -> iterator
    unordered_map<int, list<int>> freq;                 // freq -> list of keys
    int minF = 0;
    int cap = 0;

public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (cap == 0) return -1;

        if (mp.find(key) != mp.end()) {
            int oldF = kvf[key].second;
            freq[oldF].erase(mp[key]);
            if (freq[oldF].empty()) {
                freq.erase(oldF);
                if (minF == oldF)
                    minF = oldF + 1;
            }
            int newF = oldF + 1;
            kvf[key].second = newF;
            freq[newF].push_front(key);
            mp[key] = freq[newF].begin();
            return kvf[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;

        // Key already exists -> update value + bump freq
        if (mp.find(key) != mp.end()) {
            int oldF = kvf[key].second;
            freq[oldF].erase(mp[key]);
            if (freq[oldF].empty()) {
                freq.erase(oldF);
                if (minF == oldF)
                    minF = oldF + 1;
            }
            kvf[key].first = value;
            kvf[key].second = oldF + 1;
            freq[oldF + 1].push_front(key);
            mp[key] = freq[oldF + 1].begin();
            return;
        }
        if (mp.size() == cap) {
            int k = freq[minF].back();
            freq[minF].pop_back();

            if (freq[minF].empty())
                freq.erase(minF);

            mp.erase(k);
            kvf.erase(k);
        }
        minF = 1;
        freq[1].push_front(key);
        mp[key] = freq[1].begin();
        kvf[key] = { value, 1 };
    }
};
