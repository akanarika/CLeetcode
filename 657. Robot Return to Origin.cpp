class Solution {
public:
    bool judgeCircle(string moves) {
        size_t LR = 0;
        size_t UD = 0;
        for (auto c : moves) {
            switch(c) {
                case 'L':
                    LR++;
                    break;
                case 'R':
                    LR--;
                    break;
                case 'U':
                    UD++;
                    break;
                case 'D':
                    UD--;
                    break;
            }
        }
        return (LR == 0) && (UD ==0);
    }
};
