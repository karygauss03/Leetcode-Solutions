class MyHashSet {
    int size_ = 101;
    vector<list<int>> set_;
public:
    MyHashSet() : set_(size_, list<int>()){
        
    }
    
    bool search(int key) {
        auto& l = set_[key % size_];
        auto it = find(l.begin(), l.end(), key);
        return it != l.end();
    }
    
    void add(int key) {
        if (!search(key)) {
            set_[key % size_].emplace_back(key);
        }
    }
    
    void remove(int key) {
        if (search(key)) {
            set_[key % size_].remove(key);
        }
    }
    
    bool contains(int key) {
        return search(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */