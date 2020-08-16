class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int left = INT_MAX;
        int bottom = INT_MAX;
        
        int right = INT_MIN;
        int top = INT_MIN;
        
        unordered_map<string, int> cnt;
        int total_area = 0; 
        for (auto it = rectangles.begin(); it != rectangles.end(); it++) {
            vector<int>& rec = *it;
            left = min(left, rec[0]);
            bottom = min(bottom, rec[1]);
            
            right = max(right, rec[2]);
            top = max(top, rec[3]);
            
            string bl = to_string(rec[1]) + " " + to_string(rec[0]);
            string br = to_string(rec[1]) + " " + to_string(rec[2]);
            string tl = to_string(rec[3]) + " " + to_string(rec[0]);
            string tr = to_string(rec[3]) + " " + to_string(rec[2]);
            
            if (!cnt.erase(bl)) cnt[bl]++;
            if (!cnt.erase(br)) cnt[br]++;
            if (!cnt.erase(tl)) cnt[tl]++;
            if (!cnt.erase(tr)) cnt[tr]++;
            
            total_area += (rec[2] - rec[0]) * (rec[3] - rec[1]);
        }
        
        if (!cnt.count(to_string(bottom) + " " + to_string(left))
            || !cnt.count(to_string(bottom) + " " + to_string(right))
            || !cnt.count(to_string(top) + " " + to_string(left))
            || !cnt.count(to_string(top) + " " + to_string(right))) {
            return false;
        }
        
        return cnt.size() == 4 && total_area == (right - left) * (top - bottom);
    }
};