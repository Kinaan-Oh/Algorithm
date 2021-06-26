// 출제의도: "Design", Time Complexity: O(1)(push/pop/top/getMin), Space Complexity: O(n) (n: operation 갯수)
// monotone stack을 이용한 sol2의 Time/Space Complexity를 개선. sol2의 monotone stack은 단조 감소, 중복 혀용 이었다면, sol3는 단조 감소, 중복 불혀용.
// monotone stack에 최솟값 갱신시에만 삽입하며 val과 main_stack상의 위치(인덱스)을 pair로 함께 삽입해준다. 따라서, sol2의 중복된 최솟값에 대한 push/pop 연산을 생략할 수 있게 된다.

class MinStack {
private:
    stack<int>  main_stack;
    stack<pair<int,int>>  min_stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        main_stack.push(val);
        if(min_stack.empty() || min_stack.top().first>val)    min_stack.push({val,main_stack.size()-1});
    }
    
    void pop() {
        if(min_stack.top().first==main_stack.top() && min_stack.top().second==main_stack.size()-1)   min_stack.pop();
        main_stack.pop();
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        return min_stack.top().first;
    }
};
