// Stack, Time Complexity: O(l), Space Complexity: O(l) (l: s.length)

class Solution {
public:
    int maxDepth(string s) {
        int answer = 0;
        stack<char> stack;
        
        for(auto c: s) {
            if(c=='(') {
                stack.push(c);
                answer = max(answer, (int)stack.size());
            } else if(c==')') {
                stack.pop();
            }
        }
        return answer;
    }
};
