class MyCalendarTwo {
private:
    vector<pair<int, int>> events;
    vector<pair<int, int>> overlaps;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (const auto& eve : overlaps) {
            int s = eve.first;
            int e = eve.second;
            if (max(s, start) < min(e, end)) return false;
        }
        
        for (const auto& eve : events) {
            int s = eve.first;
            int e = eve.second;
            if (max(s, start) < min(e, end)) {
                overlaps.push_back(make_pair(max(s, start), min(e, end)));
            }
        }
        
        events.push_back(make_pair(start, end));
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */