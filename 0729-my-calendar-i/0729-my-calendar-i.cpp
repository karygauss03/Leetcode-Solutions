class MyCalendar {
private:
    set<pair<int, int>> myset;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (myset.empty()) {
            myset.insert({start, end});
            // cout << "Insert start and end " << start << " " << end << endl;
            return true;
        }
        
        // Check if any conflict
        for (auto temp : myset) {
            int temp_s = temp.first;
            int temp_e = temp.second;
         
            if (start >= temp_s && start < temp_e) {
                return false;
            }
            
            if (end > temp_s && end <= temp_e) {
                return false;
            }
            
            if (start <= temp_s && end >= temp_e) {
                return false;
            }
            
            if (end <= temp_s) {
                break;
            }
        }
        
        myset.insert({start, end});
        //cout << "Insert start and end " << start << " " << end << endl;
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */