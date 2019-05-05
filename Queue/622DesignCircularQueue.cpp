/**
 Solution:
 Circular queue implementation.
*/
class MyCircularQueue {
private: 
    vector<int> data;       
    int head;
    int tail;
    int n;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        head = 0;
        tail = -1;
        n = 0;
        data.resize(k);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        tail++;
        if(tail>=data.size()) tail = 0;
        data[tail] = value;
        n++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (n==0) return false;
        head++;
        if(head>=data.size()) head = 0;
        n--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(n==0) return -1;
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(n==0) return -1;
        return data[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return n==0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return n==data.size();
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