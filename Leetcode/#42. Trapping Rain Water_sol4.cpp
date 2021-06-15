// "Monotone Stack", Time Complexity: O(n), Space Complexity: O(n).
// Monotone Stack은 원소들을 내부적으로 내림차순 혹은 오름차순으로 유지한다. Monotone Stack을 사용하는 이유는 해당 원소보다 큰(내림차순) 혹은 작은(오름차순) 첫 번째 원소를 O(1)로 접근할 수 있기 때문이다.
// sol2 처럼 탐색할 경우 O(n)이 걸린다.
// 이 문제의 경우 Monotone Stack은 내림차순을 유지하고 특정 원소보다 큰(왼쪽방향으로) 첫번째 원소를 O(1)로 접근가능하다. 스택의 top보다 큰 원소를 만난다면, 해당 원소는 top의 right bound가 되고 스택 내 
// top의 직전 원소는 left bound가 된다.

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int>  st;
        for(int i=0;i<height.size();i++) {
            if(st.empty() || height[st.top()]>height[i]) {
                st.push(i);
                continue;
            }
            
            while(!st.empty() && height[st.top()]<height[i]) {
                int bottom = st.top();
                st.pop();
                if(st.empty())  break;
                ans += (min(height[st.top()],height[i]) - height[bottom])*(i-st.top()-1);
            }
            st.push(i);
        }
        
        return ans;
    }
};
