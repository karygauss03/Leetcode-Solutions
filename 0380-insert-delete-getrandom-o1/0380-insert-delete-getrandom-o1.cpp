class RandomizedSet {
private:
    unordered_set<int> st;
public:
    RandomizedSet() {
        st.clear();
    }
    
    bool insert(int val) {
        if (st.count(val) != 0) return false;
        st.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if (st.count(val) == 0) return false;
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        int random_it = rand() % st.size();
        auto it = st.begin();
        advance(it, random_it);
        return *(it);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */