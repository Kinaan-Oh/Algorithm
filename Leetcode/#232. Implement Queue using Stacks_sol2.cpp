// 출제의도: "Design", Time Complexity: push:O(1), pop/peek: amortized O(1). Space Complexity: O(n).
// stack을 push용도, pop용도 구분하여 사용. push는 무조건 push용도 stack에 함. pop은 pop용도의 stack에서 하는데, 만약에 empty라면 push stack의 모든 원소를 pop stack으로 이동.(O(n))
// pop의 Time Complexity는 Worst Case) st_pop이 empty일때 O(n), Else)  empty가 아니면 O(1)이므로 amortized O(1).

class MyQueue {
private:
    stack<int>  st_push, st_pop;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st_push.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top;
        if(st_pop.empty()) {
            while(!st_push.empty()) {
                st_pop.push(st_push.top());
                st_push.pop();
            }
        }
        
        top = st_pop.top();
        st_pop.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        int top;
        if(st_pop.empty()) {
            while(!st_push.empty()) {
                st_pop.push(st_push.top());
                st_push.pop();
            }
        }
        
        top = st_pop.top();
        return top;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st_pop.empty() && st_push.empty();
    }
};
