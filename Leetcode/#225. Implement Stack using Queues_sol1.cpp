// 출제의도: "Design", Time Complexity: push:O(1), pop:O(n), Space Complexity: O(n) (n: 원소 갯수)
// 큐의 rear를 stack의 top으로 설정한 풀이.
// 다른 풀이로, 큐의 front를 stack의 top으로 설정할 수 있음. 이 경우 Time Complexity는 push:O(n), pop:O(1). push의 경우 새로운 원소를 빈 큐에 삽입한 뒤, 기존 큐(비어있지 않았던)의 원소들을
// pop하여 비어있던 큐에 삽입 하면 front에 가장 최근의 원소가 배치됨.

class MyStack {
private:
    queue<int> que[2];
    int cur;
    
public:
    /** Initialize your data structure here. */
    MyStack() {
        cur = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        cur = !que[0].empty() ? 0 : 1;
        que[cur].push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top;
        cur = !que[0].empty() ? 0 : 1;
        while(que[cur].size()>1) {
            que[(cur+1)%2].push(que[cur].front());
            que[cur].pop();
        }
        top = que[cur].front();
        que[cur].pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        int top;
        cur = !que[0].empty() ? 0 : 1;
        while(que[cur].size()>1) {
            que[(cur+1)%2].push(que[cur].front());
            que[cur].pop();
        }
        top = que[cur].front();
        que[(cur+1)%2].push(que[cur].front());
        que[cur].pop();
        return top;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que[0].empty() && que[1].empty();
    }
};
