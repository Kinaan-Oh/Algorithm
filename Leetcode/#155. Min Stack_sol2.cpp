// 출제의도: "Design", Time Complexity: O(1)(push/pop/top/getMin), Space Complexity: O(n) (n: operation 갯수)
// sol1은 각 원소를 삽입한 각 시점에서의 최소 값을 전부 기억하는 방법인 반면, sol2는 monotone stack을 유지하는데 monotone stack의 top은 특정 시점까지 삽입한 원소까지의 최솟값을 나타낸다. 
// 각 원소를 push할 때 최소값이 갱신되거나 기존 최소값과 같은 경우 monotone stack에 삽입한다. pop할 때는 pop할 원소가 monotone stack의 top과 같을 경우에만 monotone stack을 pop해준다.

class MinStack {
private:
    stack<int>  main_stack;
    stack<int>  min_stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        main_stack.push(val);
        if(min_stack.empty() || min_stack.top()>=val)    min_stack.push(val);
    }
    
    void pop() {
        if(min_stack.top()==main_stack.top())   min_stack.pop();
        main_stack.pop();
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
