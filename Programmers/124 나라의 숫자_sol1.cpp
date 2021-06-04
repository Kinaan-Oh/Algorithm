// 출제의도: "진법변환"
// n을 3진법으로 변환한되 124 나라의 숫자로 변환.
// 124나라의 숫자가 무엇인지 정의를 내리는 것이 어려웠음. 124나라의 숫자는 기본적으로 3진법 체계를 따르지만, 0을 표현할 수 없음. 0대신 4를 채워넣고 바로 상위 자리에서 1을 감소시킴.(4의 크기는 3을 의미)

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string to_ternary(int n) {
    string ternary="";
    while(n) {
        ternary = to_string(n%3) + ternary;
        n /= 3;
    }
    return ternary;
}

string to_124(string num) {
    bool completed=false;
    while(!completed) {
        completed=true;
        for(int i=0;i<num.size();i++) {
            if(num[i]=='0') {
                completed=false;
                if(i==0) {
                    num.erase(0,1);
                    break;
                }
                num[i-1] = num[i-1]=='1' ? '0' : (num[i-1]=='2' ? '1' : '2'); 
                num[i] = '4';
                break;
            }
        }
    }
    return num;
}

string solution(int n) {
    string answer = to_124(to_ternary(n));
    return answer;
}
