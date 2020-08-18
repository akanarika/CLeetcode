/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        return findInRange(target, 0, mountainArr.length(), mountainArr);
    }
    
private:
    int findInRange(int target, int start, int end, MountainArray &A) {
        if (end <= start) return -1;
        if (end - 1 == start) {
            if (target == A.get(start)) return start;
            return -1;
        }
        
        int s = A.get(start);
        int e = A.get(end - 1);
        int mid = start + (end - start) / 2;
        int m = A.get(mid);
        if (target < s && target < e) return -1;
        // moutain type
        if (A.get(start + 1) > s && A.get(end - 2) > e) {
            int findLeft = findInRange(target, start, mid, A);
            if (findLeft >= 0) return findLeft;
            return findInRange(target, mid, end, A);
        }
        // low to high
        else if (s < e) {
            if (e < target) return -1;
            if (m > target) return findInRange(target, start, mid, A);
            return findInRange(target, mid, end, A);
        }
        // high to low
        else if (e < s) {
            if (s < target) return -1;
            if (m < target) return findInRange(target, start, mid, A);
            return findInRange(target, mid, end, A);
        }
        return -1;
    }
    
};