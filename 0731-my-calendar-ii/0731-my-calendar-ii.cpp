class MyCalendarTwo {
private:
    multiset<pair<int, int>> bookings;
public:
    MyCalendarTwo() {
        bookings.clear();
    }
    
    bool book(int start, int end) {
        int cnt = 0;
        bookings.insert({start, 0});
        bookings.insert({end - 1, 1});
        for (auto& booking: bookings) {
            if (booking.second == 0) {
                ++cnt;
            } 
            if (booking.second == 1) {
                --cnt;
            }
            if (cnt == 3) {
                bookings.erase(bookings.find({start, 0}));
                bookings.erase(bookings.find({end - 1, 1}));
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */