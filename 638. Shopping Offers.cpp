class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return shopping(price, special, 0, needs);        
    }

    int shopping(vector<int>& price, vector<vector<int>>& special, int idx, vector<int>& needs) {
        int total1 = INT_MAX;
        vector<int> needs1 = needs;
        if (isEnough(special[idx], needs1)) {
            total1 = special[idx][special[idx].size() - 1] + shopping(price, special, idx, needs1);
            for (int i = 0; i < needs1.size(); i++) {
                 total1 += needs1[i] * price[i];
            }
        } 
        
        int total2 = INT_MAX;
        if (idx < special.size() - 1) {
            total2 = shopping(price, special, idx + 1, needs);
        } else {
            total2 = 0;
        }
        for (int i = 0; i < needs.size(); i++) {
             total2 += needs[i] * price[i];
             needs[i] = 0;
        }

        return min(total1, total2);
    }

    bool isEnough(vector<int> special, vector<int>& needs) {
        for (int i = 0; i < needs.size(); i++) {
            if (special[i] > needs[i]) return false;
        }
        for (int i = 0; i < needs.size(); i++) {
            needs[i] -= special[i];
        }
        return true;
    }
};
