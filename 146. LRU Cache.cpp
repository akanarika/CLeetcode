/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
private:
    size_t cap;
    list<int> l;
    unordered_map<int, pair<list<int>::iterator, int>> kv;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (kv.count(key)) {
            // insert i to position from x: void splice (iterator position, list& x, iterator i);
            l.splice(l.begin(), l, kv[key].first);
            return kv[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (kv.count(key)) {
            // in case the value changes
            kv[key].second = value;
            l.splice(l.begin(), l, kv[key].first);
            return;
        }
        l.push_front(key);
        kv[key] = make_pair(l.begin(), value);
        if (l.size() > cap) {
            kv.erase(l.back());
            l.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

/**
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
**/

