// 출제의도: "완전탐색(순열),문자열"

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string>  parse(string expression) {
    vector<string>  parsed;
    int front=0;
    for(int i=0;i<expression.size();i++) {
        if(!isdigit(expression[i])) {
            parsed.push_back(expression.substr(front,i-front));
            parsed.push_back(expression.substr(i,1));
            front = i+1;
        }
    }
    parsed.push_back(expression.substr(front));
    return parsed;
}

void cal_infix(vector<string> &infix, string op) {
    for(int i=0;i<infix.size();i++) {
        long long result;
        if(infix[i]==op) {
            switch(op[0]) {
                case '+':
                    result = stoll(infix[i-1])+stoll(infix[i+1]);
                    break;
                case '-':
                    result = stoll(infix[i-1])-stoll(infix[i+1]);
                    break;
                case '*':
                    result = stoll(infix[i-1])*stoll(infix[i+1]);
                    break;
            }
            
            infix.erase(infix.begin()+i-1,infix.begin()+i+2);
            infix.insert(infix.begin()+i-1,to_string(result));
            i--;
        }
    }
}

long long solution(string expression) {
    long long answer = 0;
    vector<string>  parsed = parse(expression);
    vector<string> priority = {"*","+","-"};

    do {
        vector<string> infix = parsed;
        long long result=0;
        for(int i=0;i<priority.size();i++) {
            cal_infix(infix, priority[i]);
        }
        answer = max(answer, abs(stoll(infix[0])));
    } while(next_permutation(priority.begin(),priority.end()));
    return answer;
}
