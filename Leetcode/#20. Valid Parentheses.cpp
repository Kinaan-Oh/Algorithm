// 출제의도: "Stack", Time Complexity: O(n), Space Complexity: O(n) (n: s.length)
// idea: s를 왼쪽에서 오른쪽으로 관찰하면서 valid한 괄호 쌍이 발견될때마다 제거. 만약, vector를 사용할 경우 resize로 비효율적이다. 따라서, stack 혹은 double linked list를 이용할 수 있다.

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> open_bracket;
        open_bracket[')'] = '(';
        open_bracket[']'] = '[';
        open_bracket['}'] = '{';
        stack<char> st;
        for(int i=0;i<s.size();i++) {
            if(s[i]==')' || s[i]=='}' || s[i]==']') {
                if(st.empty() || st.top()!=open_bracket[s[i]])  return false;
                st.pop();
            }
            else st.push(s[i]);
        }
        if(!st.empty())    return false;
        
        return true;
    }
};
