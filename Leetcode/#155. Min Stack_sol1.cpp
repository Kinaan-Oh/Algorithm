// "Design", Time Complexity: O(1) (push/pop/top/getMin), Space Complexity: O(n) (n: operation 갯수)
// minStack에 원소 삽입시, 해당 원소를 포함한 지금까지의 최소원소 value를 minValues에 저장. 나는 minStack과 minValues 두 vector 자료구조를 이용했지만, pair로 관리한다면 하나로 합칠 수 있다.

class MinStack {
private:
    int minValue = INT_MAX;
    vector<int> minStack;
    vector<int> minValues;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        minStack.push_back(val);
        minValue = min(minValue, val);
        minValues.push_back(minValue);
    }
    
    void pop() {
        minStack.pop_back();
        minValues.pop_back();
        minValue = minValues.empty() ? INT_MAX : minValues.back();
    }
    
    int top() {
        return minStack.back();
    }
    
    int getMin() {
        return minValues.back();
    }
};
