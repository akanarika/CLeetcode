// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int bv = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool bad = isBadVersion(mid);
            if (bad) {
                bv = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return bv;
    }
};
