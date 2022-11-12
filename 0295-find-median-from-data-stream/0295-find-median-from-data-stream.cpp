class MedianFinder {
public:
    priority_queue<int> decreasing;
    priority_queue<int, vector<int>, greater<int>> increasing;
    bool evn = true;
    MedianFinder() {
    }
    void addNum(int num) {
        evn =!evn;
        if(!evn){
        decreasing.push(num);
        increasing.push(decreasing.top());
        decreasing.pop();}
        else{
              increasing.push(num);
              decreasing.push(increasing.top());
              increasing.pop();
        }
      
    }
    double findMedian() {
        if (!evn) return increasing.top();
        return (decreasing.top() + increasing.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */