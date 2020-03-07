class Solution {
public:
    string nextClosestTime(string time) {
        set<int> s;
        for (auto c : time) {
            if (c != ':') s.insert(c - '0');
        }
        int oh = stoi(time.substr(0, 2));
        int om = stoi(time.substr(3, 2));
        
        int h = 0;
        int m = 0;
        int diff = INT_MAX;
        string res = time;
        // xy:pq
        for (auto x : s) {
            if (x > 2) continue;
            for (auto y : s) {
                h = x * 10 + y;
                if (h > 23) continue;
                for (auto p : s) {
                    if (p > 6) continue;
                    for (auto q : s) {
                        m = p * 10 + q;
                        if (m > 59) continue;
                        int currDiff = diff;
                        if (h > oh || h == oh && m >= om) {
                            currDiff = (h - oh) * 60 + m - om;
                        } else {
                            currDiff = (h - oh + 24) * 60 + m - om;
                        }
                        if (currDiff != 0 && currDiff < diff) {
                            diff = currDiff;
                            res = {(x + '0'), (y + '0'), ':', (p + '0'), (q + '0')};
                        }
                    }
                }
            }
        }
        return res;
    }
};