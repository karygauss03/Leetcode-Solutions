class MyQueue {
public:
    deque<int> s1;
    
    MyQueue() {
        deque<int> tmp;
        s1 = tmp;
    }
    
    void push(int x) {
        s1.push_back(x);
    }
    
    int pop() {
        int x = s1.front();
        s1.pop_front();
        return x;
    }
    
    int peek() {
        int x = s1.front();
        return x;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */