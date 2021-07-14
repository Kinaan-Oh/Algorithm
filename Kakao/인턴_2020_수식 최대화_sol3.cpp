// "Divide and Conquer", Time Complexity: O(n), Space Complexity: O(n). (n: expression.size)
// #241. Different Ways to Add Parentheses 와 달리 DP는 사용할 수 없음. 같은 수식이라도 operator 연산 순서에 따라 값이 달라지기 때문.
// 연산자 우선순위에 따라 Time Complexity는 달라짐. 
// 반복적으로 expression이 균등하게 절반으로 나누어지는 경우가 best case로 점화식은 다음과 같다. T(n) = 2*T(n/2)+1. 따라서 Time Complexity: O(lgn), Space Complexity: O(lgn).
// 반대로, 반복적으로 expression이 한쪽으로 완전히 치우쳐서 분할되는 경우가 worst case로 점화식은 다음과 같다. T(n) = T(n-1)+1. 따라서 Time Complexity: O(n), Space Complexity: O(n).

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<char> op = {'*', '+', '-'};

long long calc(string expression) {
    long long result;
    bool fnd = false;
    
    for(int i=2; i>=0&&!fnd; i--) {
        for(int j=expression.size()-1; j>=0&&!fnd; j--) {
            if(expression[j] != op[i])    continue;
            
            fnd = true;
            switch(op[i]) {
                case '*':
                    result = calc(expression.substr(0,j))*calc(expression.substr(j+1));
                    break;
                case '+':
                    result = calc(expression.substr(0,j))+calc(expression.substr(j+1));
                    break;
                case '-':
                    result = calc(expression.substr(0,j))-calc(expression.substr(j+1));
                    break;
            }
        }
    }

    return result = (fnd ? result : stoll(expression));
}

long long solution(string expression) {
    long long answer = 0;
    
    do {
        answer = max(answer, abs(calc(expression)));
    } while(next_permutation(op.begin(), op.end()));
    
    return answer;
}
