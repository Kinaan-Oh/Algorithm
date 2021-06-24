// 출제의도: "Design", Time Complexity: O(1)(모든 연산), Space Complexity: O(n). (n: operation 갯수)
// list(double linked list)로 구현한다면 insertFront, deleteFront를 Time Complexity O(1)로 구현할 수 있음.
// c++ deque stl은 내부적으로 구현된 방식이 공개되어있지 않음. 보장할 수 있는 것은 1) list와 달리 임의 원소에 대한 접근시간은 O(1)(random accesss iterator) 2) push/pop_front는 O(1)
// 3) erase는 내부적으로 구현된 방식에 따라 달리지는데 list로 구현된 경우 O(1) 그렇지 않다면 O(n).(즉 list보다 erase 성능이좋다고 보장할 수 없음.)
// 문제에서 구현한 CircularDeque는 원소 삽입/삭제 접근이 front와 rear만 하면 되기때문에 list 자료구조를 선택하였음.

class MyCircularDeque {
private:
    list<int>   circularDeque;
    int capacity;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        this->capacity = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(circularDeque.size()==capacity)  return false;
        
        circularDeque.push_front(value);
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(circularDeque.size()==capacity)  return false;
        
        circularDeque.push_back(value);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(circularDeque.size()==0)  return false;
        
        circularDeque.pop_front();
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(circularDeque.size()==0)  return false;
        
        circularDeque.pop_back();
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(circularDeque.size()==0)  return -1;
        
        return circularDeque.front();
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(circularDeque.size()==0)  return -1;
        
        return circularDeque.back();
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return circularDeque.empty();
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return circularDeque.size()==capacity;
    }
};
