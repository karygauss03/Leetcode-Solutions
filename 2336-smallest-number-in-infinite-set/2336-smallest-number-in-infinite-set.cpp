class SmallestInfiniteSet {
public:
    set<int> infiniteSet;
    int cur;
    SmallestInfiniteSet() {
        infiniteSet.insert(1);
        cur = 2;
    }
    
    int popSmallest() {
        int smallestElement = *infiniteSet.begin();
        infiniteSet.erase(smallestElement);
        if (infiniteSet.size() == 0) {
            infiniteSet.insert(cur++);
        }
        return smallestElement;
    }
    
    void addBack(int num) {
        if (num < cur)
            infiniteSet.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */