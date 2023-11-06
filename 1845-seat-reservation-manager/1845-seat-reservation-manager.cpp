class SeatManager {
private:
    bitset<100000> res;
public:
    SeatManager(int n) {
        res.set();
    }
    
    int reserve() {
        int pos = res._Find_first();
        res.reset(pos);
        return pos+1;
    }
    
    void unreserve(int seatNumber) {
        
        res.set(seatNumber - 1);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */