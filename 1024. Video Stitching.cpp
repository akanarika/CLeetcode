class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        
        int curr = 0;
        int cnt = 0;
        while (curr < T) {
            int maxEnd = curr;
            for (const auto& clip : clips) {
                if (clip[0] <= curr) {
                    maxEnd = max(maxEnd, clip[1]);
                } else {
                    break;
                }
            }
            if (maxEnd == curr) return -1;
            cnt++;
            curr = maxEnd;
        }
        
        if (curr < T) return -1;
        return cnt;
    }
};
