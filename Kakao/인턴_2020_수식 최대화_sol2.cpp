// "중위표기식을 후위표기식으로 변환, 후위표기식의 계산", Time Complexity: O(n), Space Complexity: O(n). (n: expression.size)

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
