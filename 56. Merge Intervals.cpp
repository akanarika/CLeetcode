/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
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