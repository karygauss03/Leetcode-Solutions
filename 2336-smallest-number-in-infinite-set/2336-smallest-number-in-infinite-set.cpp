class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        current_smallest_infinite = 1;
    }
    
    int popSmallest() {
        if(!pq.empty())
        {
            int res = pq.top();
            pq.pop();
            removed[res] = 1;
            return res;
        }
        else
        {
            int res = current_smallest_infinite;
            current_smallest_infinite++;
            removed[res] = 1;
            return res;
        }
    }
    
    void addBack(int num) {
        if(removed[num] != 0)
        {
            removed[num] = 0;
            pq.push(num);
        }
    }
    
    unordered_map <int, int> removed;
    int current_smallest_infinite;
    priority_queue<int, vector<int>, greater<int>> pq;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */