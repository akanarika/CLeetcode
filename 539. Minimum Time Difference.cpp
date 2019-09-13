class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;
        for (auto time : timePoints) {
            size_t pos = time.find(':');
            int h = stoi(time.substr(0, pos));
            int m = stoi(time.substr(pos + 1));
            int min = h * 60 + m;
            mins.push_back(min);
        }

        sort(mins.begin(), mins.end());

        vector<int> mis;
        for (int i = 1; i < mins.size(); i++) {
            mis.push_back(mins[i] - mins[i - 1]);
        }
        mis.push_back(24 * 60 + mins[0] - mins[mins.size() - 1]);


        int m = 24 * 60;

        for (int mi : mis) {
            if (mi > 12 * 60) mi = 24 * 60 - mi;
            m = min(m, mi);
        }

        return m;
    }
};
