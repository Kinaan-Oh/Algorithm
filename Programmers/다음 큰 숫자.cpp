// 출제의도: "비트마스크"
// 1씩 증가시키면서 2진수로 변환시 1의 갯수가 n과 같은 수를 리턴.

#include <string>
#include <vector>

using namespace std;

int num_of_one(int n) {
    int num = 0;
    while(n) {
        num = n&1 ? num+1 : num;
        n >>= 1;
    }
    return num;
}

int solution(int n) {
    int answer = 0;
    int num = num_of_one(n);
    answer = n+1;
    while(num_of_one(answer)!=num) {
        answer++;
    }
    return answer;
}
