class HitCounter {
private:
    unordered_map<int, int> table;
public:
    /** Initialize your data structure here. */
    HitCounter() {
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        table[timestamp]++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int sum = 0;
        for (int i = max(1, timestamp - 299); i <= timestamp; i++) {
            sum += table[i];
        }
        return sum;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
