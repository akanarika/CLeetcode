class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), greater<int>());

        vector<int> arr;
        for (auto num : deck) {
            if (arr.empty()) {
                arr.push_back(num);
                continue;
            }
            int last = arr[arr.size() - 1];
            arr.push_back(0);
            for (int i = arr.size() - 1; i >= 2; i--) {
                arr[i] = arr[i - 2];
            }
            arr[0] = num;
            arr[1] = last;
        }
        return arr; 
    }
};
