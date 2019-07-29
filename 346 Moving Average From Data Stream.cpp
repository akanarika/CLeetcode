class MovingAverage {
private:
    size_t currentSize;
    size_t maxSize;
    double ave;
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        currentSize = 0;
        maxSize = size;
        ave = 0;
    }
    
    double next(int val) {
        q.push(val);
        if (currentSize < maxSize) {
            currentSize++;
            ave = (ave * (currentSize - 1) + val) / currentSize;
        } else {
            ave = (ave * currentSize - q.front() + val) / currentSize;
            q.pop();
        }
        return ave;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
