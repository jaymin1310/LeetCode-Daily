class LFUCache {
    unordered_map<int, pair<int,int>> kvf;
    unordered_map<int, list<int>::iterator> mp;
    unordered_map<int, list<int>> freq;
    int minF = 0, cap = 0;

    void increaseFreq(int key) {
        int oldF = kvf[key].second;
        auto it = mp[key];

        // remove from old frequency bucket
        auto &lst = freq[oldF];
        lst.erase(it);

        // check if bucket empty
        if (lst.empty()) {
            freq.erase(oldF);
            if (minF == oldF)
                minF = oldF + 1;
        }

        // add to new bucket
        int newF = oldF + 1;
        kvf[key].second = newF;
        freq[newF].push_front(key);
        mp[key] = freq[newF].begin();
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        kvf.reserve(cap);
        mp.reserve(cap);
        freq.reserve(cap);
    }
    
    int get(int key) {
        if (cap == 0 || mp.find(key) == mp.end()) 
            return -1;

        increaseFreq(key);
        return kvf[key].first;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;

        if (mp.find(key) != mp.end()) {
            kvf[key].first = value;
            increaseFreq(key);
            return;
        }

        // eviction
        if ((int)mp.size() == cap) {
            auto &lst = freq[minF];
            int k = lst.back();
            lst.pop_back();
            
            if (lst.empty())
                freq.erase(minF);

            mp.erase(k);
            kvf.erase(k);
        }

        minF = 1;
        freq[1].push_front(key);
        mp[key] = freq[1].begin();
        kvf[key] = {value, 1};
    }
};
