// 출제의도: "진법변환, borrow(빌림)"
// 124나라는 기본적으로 3진법이나, 0을 표현할 수 없다. 0은 높은 자리수에서 빌려(borrow) 4로 채운다.(숫자 4의 크기는 실질적으로 3을 의미)
// 124나라와 3진법의 유사/차이점은 식별하였으나, 구체적인 차이점을 분석해내지 못하였었다. 124나라에는 0이 없다는 점, 0대신 4를 채운다는 점(4의 크기는 3)을 명확히 파악했어야 했다.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string to_ternary(int n) {
    string ternary="";
    while(n) {
        if(n%3){
            ternary = to_string(n%3) + ternary;
            n /= 3;
        }
        else {
            ternary = "4" + ternary;
            n = n/3 - 1;
        }
    }
    return ternary;
}

string solution(int n) {
    string answer = to_ternary(n);
    return answer;
}
