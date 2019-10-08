/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/**
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) return intervals;
        sort(intervals.begin(), intervals.end(), [](Interval &left, Interval &right) {
            return left.start < right.start;
        });
        int p = 0;
        while (p < intervals.size() - 1) {
            if (intervals[p].end >= intervals[p+1].start) {
                intervals[p].end = max(intervals[p].end, intervals[p+1].end);
                intervals.erase(intervals.begin() + p + 1);
            } else {
                p++;
            }
        }
        return intervals;
    }
};
**/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (int i = 0; i < intervals.size(); i++) {
            m[intervals[i][0]] = max(m[intervals[i][0]], intervals[i][1]);
        }

        int end = INT_MIN;
        vector<vector<int>> res;
        for (auto p : m) {
            if (p.first <= end) {
                res[res.size() - 1][1] = max(p.second, end);
            } else {
                res.push_back({p.first, p.second});
            }
            end = max(p.second, end);
        }
        return res;
    }
};
