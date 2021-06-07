// 출제의도: "Stack", Time Complexity: O(n), Space Complexity: O(n)
// 올바른 괄호: (로 열렸으면 반드시 짝지어서 )로 닫혀야 한다. 1) ")" 은 (에 짝지어 닫힌것이 아니므로 틀린 괄호. 2) "(" 은 (에 짝지은 )가 없으므로 틀린 괄호.
// "()()()()"와 같이 1개씩 짝짓는 제한은 없다. "((()))"와 같이 (와)는 연속으로 짝지어질 수 있다. 전자의 경우 자료구조의 이용이 필요 없으나, 후자의 경우 (를 저장하기 위한 자료구조가 필요하다.
// 일련의 (을 저장해 놓고 수식 기준 가장 우측의 (부터 짝지어지는 )가 발견되면 제거한다. 이에 적합한 자료구조는 push()/pop(), push_back()/pop_back()를 제공하는 Stack, Vector가 있다.

// 틀린 괄효는 다음과 같이 2가지 케이스로 구분된다.
// 1) Stack에 저장된 일련의 (에 짝지은 )가 없다면, (는 pop되지 못하고 남게 되고 이는 올바른 괄효가 되지 못한다.
// 2) )과 짝지은 (가 Stack에 없다면(empty),   이는 올바른 괄호가 되지 못한다.

#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    for(int i=0;i<s.size();i++) {
        switch(s[i]){
            case '(':
                st.push('(');
                break;
            case ')':
                if(st.empty())  return false;
                st.pop();
                break;
        }
    }
    answer = st.empty() ? true : false;
    return answer;
}
