class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.size() <= right.size()) {
            left.push(num);
        } else {
            right.push(num);
        }
        if (!right.empty() && right.top() < left.top()) {
            left.push(right.top());
            right.pop();
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if (left.empty()) return -1;
        if (left.size() > right.size()) return left.top();
        else return (left.top() + right.top()) / 2.0;
    }
};

/**

class MedianFinder {
    priority_queue<int, vector<int>> small;
    priority_queue<int, vector<int>, greater<int>> big;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (small.empty() && big.empty()) small.push(num);
        else if (small.empty() || small.top() >= num) small.push(num);
        else big.push(num);
        while (small.size() < big.size()) {
            small.push(big.top());
            big.pop();
        } 
        while (small.size() > 1 + big.size()) {
            big.push(small.top());
            small.pop();
        }
    }
    
    double findMedian() {
        if ((small.size() + big.size()) % 2) return (double)small.top();
        return ((double)small.top() + (double)big.top()) / 2.0;
    }
};

 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
