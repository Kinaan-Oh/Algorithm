// 출제의도: "Math", Time Complexity: O(n), Space Complexity: O(1).
// 정수론: 자연수 n을 연속된 자연수로 표현하는 방법의 수는 n의 홀수 약수의 갯수와 같다.
// 효율적 풀이를 고민하면서 약수에 대한 패턴을 관찰하였으나, 규칙을 확정짓지는 못하였다. 수학 지식이 효율적인 코드 작성에 크게 도움이 된다는 것을 배울 수 있었다.

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1;i<=n;i++) {
        if(n%i==0 && i%2==1) {
            answer++;
        }
    }
    return answer;
}
