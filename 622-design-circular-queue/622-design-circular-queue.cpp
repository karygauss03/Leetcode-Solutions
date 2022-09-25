class MyCircularQueue {
public:
    int s=0;
    int e=0;
    int siz=0;
    int maxsize = 0;
    int arr[3000];
    
    MyCircularQueue(int k) {
        maxsize=k;
    }
    
    bool enQueue(int value) {
        if(siz == maxsize) return false;
     
        arr[e]=value;
        e++;
        siz++;
        return true;
    }
    
    bool deQueue() {
        if(siz==0) return false;
		
        s++;
        siz--;
        return true;
    }
    
    int Front() {
        if(siz==0) return -1;
		
        return arr[s];
    }
    
    int Rear() {
        if(siz==0) return -1;
		
        return arr[e-1];    
    }
    
    bool isEmpty() {
        if(siz==0) return true;
		
        return false;
    }
    
    bool isFull() {
        return siz==maxsize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */