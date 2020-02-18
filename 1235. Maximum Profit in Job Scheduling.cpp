/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
class Solution {
public:
    typedef pair<int, int> pi;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        priority_queue<pi, vector<pi>, greater<pi>> endTimes;
        unordered_map<int, unordered_map<int, int>> endToStartToPro;
        unordered_map<int, unordered_set<int>> startToEnd;
        int maxEnd = 0;
        for (int i = 0; i < startTime.size(); i++) {
            endToStartToPro[endTime[i]][startTime[i]] = max(endToStartToPro[endTime[i]][startTime[i]], profit[i]);
            startToEnd[startTime[i]].insert(endTime[i]);
            maxEnd = max(maxEnd, endTime[i]);
        }
        
        vector<int> maxPro(maxEnd + 1, 0);
        int maxRes = 0;
        for (int time = 1; time <= maxEnd; time++) {
            if (maxPro[time] == 0 && time > 1) maxPro[time] = maxPro[time - 1];
            if (startToEnd.count(time)) {
                for (auto end : startToEnd[time]) {
                    endTimes.push(make_pair(end, time));
                }
            }
            while (!endTimes.empty() && endTimes.top().first == time) {
                int start = endTimes.top().second;
                int pro = endToStartToPro[time][start];
                maxPro[time] = max(maxPro[time], maxPro[start] + pro);
                endTimes.pop();
            }
            maxRes = max(maxRes, maxPro[time]);
        }
        return maxRes;
    }
};
// @lc code=end
