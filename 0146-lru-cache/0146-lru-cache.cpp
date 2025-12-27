class LRUCache {
    list<pair<int,int>>li;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
    int cap;
public:
    
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        auto it=mp.find(key);
        if(it!=mp.end()){
            li.splice(li.begin(), li, it->second);
            return it->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it=mp.find(key);
        if(it!=mp.end()){
            li.splice(li.begin(), li, it->second);
            it->second->second=value;
        }else{
            if(mp.size()==cap){
                mp.erase(li.back().first);
                li.pop_back();
            }
            li.push_front({key,value});
            mp[key]=li.begin();
        }
    }
};