class MyCalendarThree {
public:
    map<int, int> ma;
    MyCalendarThree() {
        ;
    }
    
    int book(int start, int end) {
        ma[start]++;
        ma[end]--;
        int ans = 0;
        int sum = 0;
        for (auto &i : ma){
            sum += i.second;
            ans = max(ans, sum);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */