// 출제의도: "Design", Time Complexity: push:O(1), pop:O(n), Space Complexity: O(n)
// 큐 1개만 사용한 풀이.

class MyStack {
private:
    queue<int>  que;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int sz = que.size();
        int top;
        for(int i=0;i<sz-1;i++) {
            que.push(que.front());
            que.pop();
        }
        top = que.front();
        que.pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        int sz = que.size();
        int top;
        for(int i=0;i<sz-1;i++) {
            que.push(que.front());
            que.pop();
        }
        top = que.front();
        que.push(top);
        que.pop();
        
        return top;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};
