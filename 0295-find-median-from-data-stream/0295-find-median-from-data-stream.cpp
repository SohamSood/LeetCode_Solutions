class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minheap.size() == 0) {
            minheap.push(num);
            return;
        }
        if(minheap.top() <= num) {
            if(minheap.size() == maxheap.size()) {
                minheap.push(num);
            } else {
                minheap.push(num);
                maxheap.push(minheap.top());
                minheap.pop();
            }
        } else {
            if(minheap.size() == maxheap.size()) {
                maxheap.push(num);
                minheap.push(maxheap.top());
                maxheap.pop();
            } else {
                maxheap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(maxheap.size() == 0) return minheap.top();
        if(minheap.size() == maxheap.size()) return (double)(minheap.top() + maxheap.top()) / 2;
        return minheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */