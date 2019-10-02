class LRUCache {
    unordered_map<int, list<pair<int, int>>::iterator> lit;
    list<pair<int, int>> l;
    int size;
    int cap;
public:
    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
    }
    
    int get(int key) {
        auto found = lit.find(key);
        if (found != lit.end()) {
            l.splice(l.begin(), l, found->second);
            lit[key] = l.begin();
            return found->second->second;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto found = lit.find(key);
        if (found != lit.end()) {
            l.splice(l.begin(), l, found->second);
            found->second->second = value;
            lit[key] = l.begin();
        } else {
            l.push_front(make_pair(key, value));
            lit[key] = l.begin();
            size++;
            if (size > cap) {
                int del = l.back().first;
                l.pop_back();
                lit.erase(del);
            }
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
