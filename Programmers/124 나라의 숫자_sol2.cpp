// 출제의도: "진법변환"
// sol1과 다르게 바로 124 나라의 숫자로 변환.
// n%3이 0인 경우 4로 채워넣고 상위 자리수를 1 감소시킴(n = n/3-1)

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
