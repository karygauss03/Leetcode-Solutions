class SeatManager {
private:
    set<int> availableSeats;
public:
    SeatManager(int n) {
        availableSeats.clear();
        for (int i = 1 ; i <= n ; ++i) {
            availableSeats.insert(i);
        }
    }
    
    int reserve() {
        int availableSeat = *availableSeats.begin();
        availableSeats.erase(availableSeats.begin());
        return availableSeat;
    }
    
    void unreserve(int seatNumber) {
        availableSeats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */