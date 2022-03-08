// Stack, Time Complexity: O(1) except popMax(O(n)), Space Complexity: O(n) (n: num of operations)
// 논리: 1) 삽입순서 유지를 위한 stk. 2) max 원소를 O(1)로 파악하기 위한 monotone increasing stack maxStack. 

class MaxStack {
    stack<int>  stk;
    stack<int>  maxStk;
public:
   void push(int x) {
       stk.push(x);
       if (maxStk.empty() || maxStk.top()<=x) maxStk.push(x);
       else maxStk.push(maxStk.top());
    }
    int pop() {
        int ret = stk.top();
        stk.pop();
        maxStk.pop();
        return ret;
    }
    int top() {
        return stk.top(); 
    }
    int peekMax() {
        return maxStk.top(); 
    }
    int popMax() { 
        int ret = peekMax();
        stack<int> tmp;
        
        while(top()!=ret) {
            tmp.push(pop());
        }
        pop();
        while(!tmp.empty()) {
            push(tmp.top()); 
            tmp.pop();
        }
        return ret;
    }
};
