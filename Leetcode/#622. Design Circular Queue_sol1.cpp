// 출제의도 : Design, Time Complexity: 모든 Operation O(1), Space Complexity: O(n). (n: size)
// 배열을 사용한 가장 단순한 풀이.

class MyCircularQueue {
private:
    int queue[1000];
    int size;
    int front;
    int rear;
    
public:
    MyCircularQueue(int k) {
        fill(queue, queue+1000, -1);
        size = k;
        front = 0;
        rear = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        
        queue[rear] = value;
        rear = (rear + 1) % size;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        
        queue[front] = -1;
        front = (front + 1) % size;
        return true;
    }
    
    int Front() {
        return queue[front];
    }
    
    int Rear() {
        int pos = rear-1 >= 0 ? rear-1 : size-1 ;
        return queue[pos];
    }
    
    bool isEmpty() {
        return (front == rear) && queue[front] == -1;
    }
    
    bool isFull() {
        return (front == rear) && queue[front] != -1;
    }
};
