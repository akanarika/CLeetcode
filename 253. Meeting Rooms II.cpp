class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        int count = 0;
        int res = 0;
        for (const auto& interval : intervals) {
            while (!pq.empty()) {
                if (pq.top() <= interval[0]) {
                    pq.pop();
                    count--;
                } else break;
            }
            pq.push(interval[1]);
            count++;
            res = max(count, res);
        }
        return res;
    }
};