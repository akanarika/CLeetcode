class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // 2 segments overlap iff left1 < right2 && left2 < right1
        // so rectangles overlap if they both overlap on x axis and y axis
        return (rec1[0] < rec2[2] && rec2[0] < rec1[2])
            && (rec1[1] < rec2[3] && rec2[1] < rec1[3]);
        
        /**
        if (rec1[0] > rec2[0]) swap(rec1, rec2);
        
        if (rec2[0] < rec1[2] && (rec2[3] > rec1[1] && rec2[1] < rec1[3])) return true;
        return false;
        **/
    }
};