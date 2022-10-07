class ListNodeH{
    public:
        ListNodeH *next, *prev;
        int val;
        ListNodeH(int val){
            this->val = val;
            next = prev = NULL;
        }
};
class MyCircularDeque {
public:
    ListNodeH *head, *tail;
    ListNodeH *dummyHead, *dummyTail;
    int k, currSize;
    MyCircularDeque(int k) {
        dummyHead = new ListNodeH(0);
        dummyTail = new ListNodeH(0);
        head = dummyHead;
        tail = dummyTail;
        head->next = tail;
        tail->prev = head;
        this->k = k;
        currSize = 0;
    }
    bool insertFront(int value) {
        if(currSize == k) return false;
        ListNodeH *newNode = new ListNodeH(value);
        ListNodeH *temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        temp->prev = newNode;
        newNode->prev = head;
        currSize++;
        return true;
    }
    bool insertLast(int value) {
        if(currSize == k) return false;
        ListNodeH *newNode = new ListNodeH(value);
        ListNodeH *temp = tail->prev;
        newNode->next = tail;
        tail->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        currSize++;
        return true;
    }
    bool deleteFront() {
        if(currSize == 0) return false;
        head->next = head->next->next;
        head->next->prev = head;
        currSize--;
        return true;
    }
    
    bool deleteLast() {
        if(currSize == 0) return false;
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;
        currSize--;
        return true;
    }
    
    int getFront() {
        if(currSize == 0) return -1;
        return head->next->val;
    }
    
    int getRear() {
        if(currSize == 0) return -1;
        return tail->prev->val;
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */