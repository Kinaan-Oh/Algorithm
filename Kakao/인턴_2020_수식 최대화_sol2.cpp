// "중위표기식을 후위표기식으로 변환, 후위표기식의 계산", Time Complexity: O(n), Space Complexity: O(n). (n: expression.size)
// N사 기술면접에서 출제되었던 주제. 당시 동작 원리를 사실상 암기했었기에 해결할 수 있었지만 깊이있게 이해하지는 못했다고 생각한다.
// 중위표기식을 후위표기식으로 바꾸기 위해 스택을 사용하는 것은 monotone stack 기법임을 이번기회로 뒤늦게 알게됬다. 결과적으로 우선순위 기반 스택에는 단조증가 형태로 operator들이 유지된다.
// 그 이유는 새로 들어올 operator보다 우선순위가 크거나 같은 것은 pop하여 후위표기식에 추가 해주기 때문이다.
// 중위표기식을 후위표기식으로 바꾸어 수식계산하는 이유는 후위표기식의 계산은 연산자 우선순위를 고려하지 않고 왼쪽에서 오른쪽으로 순서대로 계산하여 결과를 얻을 수 있기 때문이다.

#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<char,int>    op_precedence;

void set_op_precedence(vector<char> op) {
    for(int i=0;i<3;i++) {
        op_precedence[op[i]] = i+1;
    }
}

vector<string> infix_to_postfix(vector<string> infix) {
    vector<string>  postfix;
    stack<string>   st;
    
    for(int i=0;i<infix.size();i++) {
        if(isdigit(infix[i][0])) {
            postfix.push_back(infix[i]);
            continue;
        }
        
        while(!st.empty() && op_precedence[st.top()[0]]<=op_precedence[infix[i][0]]) {
            postfix.push_back(st.top());
            st.pop();
        }
        st.push(infix[i]);
    }
    
    while(!st.empty()) {
        postfix.push_back(st.top());
        st.pop();
    }
    
    return postfix;
}

vector<string>  split(string expression) {
    vector<string> result;
    string unit;
    
    for(int i=0;i<expression.size();i++) {
        if(isdigit(expression[i])) {
            unit += expression[i];
            continue;
        }
        
        result.push_back(unit);
        result.push_back(expression.substr(i,1));
        unit = "";
    }
    result.push_back(unit);
    return result;
}

long long calc_postfix(vector<string> postfix) {
    long long result = 0;
    stack<long long> st;
    
    for(int i=0;i<postfix.size();i++) {
        if(isdigit(postfix[i][0])) {
            st.push(stoll(postfix[i]));
            continue;
        }
        
        long long operand2 = st.top();
        st.pop();
        long long operand1 = st.top();
        st.pop();
        
        switch(postfix[i][0]) {
            case '*':
                st.push(operand1*operand2);
                break;
            case '+':
                st.push(operand1+operand2);
                break;
            case '-':
                st.push(operand1-operand2);
                break;
        }
    }
    result = abs(st.top());
    return result;
}

long long solution(string expression) {
    long long answer = 0;
    vector<char> op = {'*', '+', '-'};
    vector<string>  splitted = split(expression);

    do {
        set_op_precedence(op);
        vector<string> postfix = infix_to_postfix(splitted);
        answer = max(answer, calc_postfix(postfix));
        
    } while(next_permutation(op.begin(), op.end()));
    
    return answer;
}
