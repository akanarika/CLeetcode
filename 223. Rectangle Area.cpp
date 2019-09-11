class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (A > E) {
            swap(A, E);
            swap(B, F);
            swap(C, G);
            swap(D, H);
        }

        // contain
        if ((C >= G) && (B <= F) && (D >= H)) {
            return (C - A) * (D - B);
        }

        // intersect
        if ((C >= E) && (F <= D) && ((H >= B) || ((H >= B) && F <= D))) {
            return (C - A) * (D - B) + (G - E) * (H - F) - (min(C, G) - E) * (min(D, H) - max(B, F));
        }
        
        return (C - A) * (D - B) + (G - E) * (H - F);
    }
};
