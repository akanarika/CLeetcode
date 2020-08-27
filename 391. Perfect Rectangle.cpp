class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<string> set;
        int area = 0;
        int min_x = INT_MAX;
        int min_y = INT_MAX;
        int max_x = INT_MIN;
        int max_y = INT_MIN;
        
        for (const auto& rec : rectangles) {
            area += (rec[2] - rec[0]) * (rec[3] - rec[1]);
            min_x = min(min_x, rec[0]);
            min_y = min(min_y, rec[1]);
            max_x = max(max_x, rec[2]);
            max_y = max(max_y, rec[3]);
            const string ax = to_string(rec[0]);
            const string ay = to_string(rec[1]);
            const string bx = to_string(rec[2]);
            const string by = to_string(rec[3]);
            
            if (!set.erase(ax + ay)) set.insert(ax + ay);
            if (!set.erase(bx + ay)) set.insert(bx + ay);
            if (!set.erase(bx + by)) set.insert(bx + by);
            if (!set.erase(ax + by)) set.insert(ax + by);
        }
        
        return area == (max_y - min_y) * (max_x - min_x)
            && set.size() == 4
            && set.count(to_string(min_x) + to_string(min_y)) 
            && set.count(to_string(min_x) + to_string(max_y))
            && set.count(to_string(max_x) + to_string(min_y))
            && set.count(to_string(max_x) + to_string(max_y));
    }
};