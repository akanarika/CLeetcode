class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxfreq = 0;
        int maxfreqCnt = 0;
        for (const auto& t : tasks) {
            freq[t - 'A']++;
            if (freq[t - 'A'] > maxfreq) {
                maxfreq = freq[t - 'A'];
                maxfreqCnt = 1;
            } else if (freq[t - 'A'] == maxfreq) {
                maxfreqCnt++;
            }
        }
        
        int empty = (n + 1 - maxfreqCnt) * (maxfreq - 1);
        int total = tasks.size();
        if (empty <= 0) return total;
        return max(0, empty - (total - maxfreqCnt * maxfreq)) + total;
    }
};

/**
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
**/
