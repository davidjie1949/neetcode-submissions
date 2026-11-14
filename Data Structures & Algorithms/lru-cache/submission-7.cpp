class LRUCache {
public:
    LRUCache(int capacity) : cap_(capacity) {
        
    }
    
    int get(int key) {
        auto it = mp_.find(key);
        if (it == mp_.end()) return -1;
        dll_.splice(dll_.begin(), dll_, it->second); // move node to front
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = mp_.find(key);
        if (it != mp_.end()) {
            it->second->second = value;
            dll_.splice(dll_.begin(), dll_, it->second);
            return;
        }

        if ((int)dll_.size() == cap_) {
            mp_.erase(dll_.back().first);
            dll_.pop_back();
        }

        dll_.emplace_front(key, value);
        mp_[key] = dll_.begin();
    }
private:
    int cap_;
    list<pair<int,int>> dll_;
    unordered_map<int, list<pair<int,int>>::iterator> mp_;
};
