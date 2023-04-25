class SmallestInfiniteSet {
public:
    map<int, int> infiniteSet;
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++) {
            infiniteSet[i]++;
        }
    }
    
    int popSmallest() {
        int smallestElement = infiniteSet.begin()->first;
        infiniteSet.erase(smallestElement);
        return smallestElement;
    }
    
    void addBack(int num) {
        infiniteSet[num]++;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */