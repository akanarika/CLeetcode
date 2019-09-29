class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26, 0);
        int maxFre = 0;
        int maxEle = 0;
        for (auto task : tasks) {
            v[task - 'A']++;
            int count = v[task - 'A'];
            if (count > maxFre) {
                maxFre = count;
                maxEle = 1;
            } else if (count == maxFre) {
                maxEle++;
            }
        }
        
        if (maxEle > n) return tasks.size();
        int emptyLength = n - (maxEle - 1);
        int emptyCount = maxFre - 1;
        int idle = emptyLength * emptyCount - (tasks.size() - maxFre * maxEle);
        int interval = tasks.size() + (idle > 0 ? idle : 0);
        return interval;
    }
};