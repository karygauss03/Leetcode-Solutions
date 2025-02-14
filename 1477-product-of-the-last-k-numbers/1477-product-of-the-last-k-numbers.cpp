class ProductOfNumbers {
private:
    vector<long long> prefix;
public:
    ProductOfNumbers() {
        prefix.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            prefix = {1};
        }
        else {
            prefix.push_back(num * prefix.back());
        }
    }
    
    int getProduct(int k) {
        if (k >= prefix.size()) {
            return 0;
        }
        return prefix.back() / prefix[prefix.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */