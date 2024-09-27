class MyCalendarTwo {
private:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlapIntervals;
    bool intersect(pair<int, int> interval, int start, int end) {
        int st = max(interval.first, start);
        int nd = min(interval.second, end);
        if (st < nd) {
            return true;
        }
        return false;
    }
    
    pair<int, int> extractOverlap(pair<int, int> booking, int start, int end) {
        return make_pair(max(booking.first, start), min(booking.second, end));
    }

public:
    MyCalendarTwo() {
        bookings.clear();
        overlapIntervals.clear();
    }
    
    bool book(int start, int end) {
        for (auto &interval : overlapIntervals) {
            if (intersect(interval, start, end)) {
                return false;
            }
        }
        for (auto &book : bookings) {
            if (intersect(book, start, end)) {
                overlapIntervals.push_back(extractOverlap(book, start, end));
            }
        }
        bookings.push_back(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */