// 출제의도: "Design", Time Complexity: push:O(n), top/pop:O(1) Space Complexity: O(n).

class MyQueue {
private:
    stack<int>  st[2];
    int cur;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        cur = !st[0].empty() ? 0 : 1;
        while(!st[cur].empty()) {
            st[(cur+1)%2].push(st[cur].top());
            st[cur].pop();
        }
        st[cur].push(x);
        while(!st[(cur+1)%2].empty()) {
            st[cur].push(st[(cur+1)%2].top());
            st[(cur+1)%2].pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        cur = !st[0].empty() ? 0 : 1;
        int front = st[cur].top();
        st[cur].pop();
        return  front;
    }
    
    /** Get the front element. */
    int peek() {
        cur = !st[0].empty() ? 0 : 1;
        return st[cur].top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st[0].empty() && st[1].empty();
    }
};
