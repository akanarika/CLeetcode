class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger < desiredTotal) return false;
        return canWin(0, desiredTotal, maxChoosableInteger);
    }
private:
    unordered_map<int, int> dict;
    bool canWin(int s, int desiredTotal, int maxChoosableInteger) {
        if (dict.count(s)) {
            return dict[s] == 1 ? true : false;
        }
        for (int x = 1; x <= maxChoosableInteger; x++) {
            if (s & (1 << x)) continue;
            if (x >= desiredTotal) return true;
            if (!canWin(s | (1 << x), desiredTotal - x, maxChoosableInteger)) {
                dict[s] = 1;
                return true;
            }
        }
        
        dict[s] = -1;
        return false;
    }
};
