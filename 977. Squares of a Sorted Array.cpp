class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        if (A.empty()) return {};
        int small = INT_MAX;
        int p = 0;
        for (int i = 0; i < A.size(); i++) {
            if (abs(A[i]) < small) {
                small = abs(A[i]);
                p = i;
            }
        }
        
        vector<int> res = {small * small};
        int left = p - 1;
        int right = p + 1;
        while (left >= 0 || right < A.size()) {
            if (left < 0 || right < A.size() && abs(A[left]) >= abs(A[right])) {
                res.push_back(A[right] * A[right]);
                right++;
            } else if (right >= A.size() || left >= 0 && abs(A[left]) < abs(A[right])) {
                res.push_back(A[left] * A[left]);
                left--;
            }
        }
        return res;
    }
};