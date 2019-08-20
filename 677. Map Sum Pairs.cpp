class MapSum {
public:
    /** Initialize your data structure here. */
    char val;
    int count;
    unordered_map<char, MapSum*> cnode;

    MapSum() {
    }
    
    void insert(string key, int val) {
        char c = key[0];
        if (cnode.find(c) == cnode.end()) {
            MapSum* nc = new MapSum();
            nc->val = c;
            nc->count = 0;
            cnode[c] = nc;
        }
        if (key.length() == 1) cnode[c]->count = val;
        if (key.length() > 1) cnode[c]->insert(key.substr(1), val);
    }
    
    int sum(string prefix) {
        if (prefix.empty()) {
            int sum = count;
            for (auto node : cnode) {
                sum += (node.second)->sum("");
            }
            return sum;
        }
        char c = prefix[0];
        if (cnode.find(c) == cnode.end()) return 0;
        return cnode[c]->sum(prefix.substr(1));
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
