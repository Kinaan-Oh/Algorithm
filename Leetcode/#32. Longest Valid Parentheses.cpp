// Stack/Slding Window, Time Complexity: O(n), Space Complexity: O(n) (n: s.length)
// 논리: 1. stack은 non-valid parentheses를 contain.
//      2. )는 stack.top이 (인 경우 update answer.
//      3. ()()와 같은 case를 처리하기 위해 stack은 초기값 -1를 보유.
// Stack를 활용한 Brute-Force로도 풀이 가능.(Time Complexity: O(n^3))

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>  st;
        int answer = 0;
        
        st.push(-1);
        
        for(int i=0;i<s.length();i++) {
            if(s[i]=='(') {
                st.push(i);
            } else {
                st.pop();
                
                if(st.empty()) {
                    st.push(i);
                } else {
                    answer = max(answer, i-st.top());
                }
            }
        }
        return answer;
    }
};
