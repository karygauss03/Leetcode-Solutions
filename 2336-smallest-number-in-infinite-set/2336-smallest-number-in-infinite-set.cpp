class SmallestInfiniteSet {
public:
    set<int> infiniteSet;
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++) {
            infiniteSet.insert(i);
        }
    }
    
    int popSmallest() {
        int smallestElement = *infiniteSet.begin();
        infiniteSet.erase(smallestElement);
        return smallestElement;
    }
    
    void addBack(int num) {
        infiniteSet.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */