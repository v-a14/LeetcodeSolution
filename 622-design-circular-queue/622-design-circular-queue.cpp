class MyCircularQueue {
public:
    vector<int>arr;
    int i = -1, j = -1;
    int k, currSize;
    MyCircularQueue(int k) {
        arr.resize(k);
        i = -1, j = -1;
        this->k = k;
        this->currSize = 0;
    }
    
    bool enQueue(int value) {
        if(currSize == k) return false;
        i = i + 1;
        i = i%k;
        currSize++;
        arr[i] = value;
        return true;
    }
    
    bool deQueue(){
        if(currSize == 0) return false;
        j = j + 1;
        j = j%k;
        currSize--;
        return true;
    }
    int Front(){
        if(currSize == 0) return -1; 
        return arr[(j+1)%k];
    }
    
    int Rear() {
        if(currSize == 0) return -1;
        return arr[i];
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == k;
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