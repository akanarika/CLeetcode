class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());

        int i = 0;
        int j = 0;
        while(i < slots1.size() && j < slots2.size()) {
            while (slots1[i][1] - slots1[i][0] < duration) {
                ++i;
                if (i == slots1.size()) return {};
            }
            while (slots2[j][1] - slots2[j][0] < duration) {
                ++j;
                if (j == slots2.size()) return {};
            }
            if (min(slots1[i][1], slots2[j][1])
                - max(slots1[i][0], slots2[j][0]) < duration) {
                if (slots1[i][1] < slots2[j][1]) ++i;
                else ++j;
            } else {
                int start = max(slots1[i][0], slots2[j][0]);
                return {start, start + duration};
            }
        }
        
        return {};
    }
};
