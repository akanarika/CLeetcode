class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> set;
        for (string a : A) {
            string sortedEven;
            string sortedOdd;
            for (size_t i = 0; i < a.length(); i++) {
                if (i % 2) {
                    sortedOdd += a[i];
                } else {
                    sortedEven += a[i];
                }
                
            }
            sort(sortedOdd.begin(), sortedOdd.end());
            sort(sortedEven.begin(), sortedEven.end());
            set.insert(sortedOdd + sortedEven);
            
        }
        return set.size();
    }
};
