class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;

        for (const auto& d : deck) {
            m[d]++;
        }
        
        vector<int> count;
        for (const auto& pair : m) {
            count.push_back(pair.second);
        }
        sort(count.begin(), count.end());

        int minCount = count[0];
        vector<int> arr(minCount + 1, 1);
        arr[0] = 0;

        for (int i = 2; i <= minCount; i++) {
            if (arr[i] == 1) {
                bool has = true;
                for (auto c : count) {
                    if (c % i != 0) {
                        int j = 2;
                        while (j * c <= minCount) {
                            arr[j * c] = 0;
                            j++;
                        }
                        has = false;
                        break;
                    }
                }
                if (has) return true;
            }
        }
        return false;
    }
};
