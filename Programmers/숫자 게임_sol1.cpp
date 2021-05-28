// 출제의도: "greey, 정렬", Time Complexity: O(nlgn), Space Complexity: O(1) (n: A.size)
// 매 순간, 상대방의 가장 큰 숫자를 내가 가진 최대한 큰 숫자로 승리할 수 있도록 결정. 이를위해 "정렬"을 사용하면 효율적으로 구현할 수 있음.(정렬을 사용하지 않으면 O(n^2))
// 최적해는 유일하지 않지만, 상대방의 가장 쿤 숫자를 내가 가진 임의의 숫자로 승리하도록 결정한다면 나중에 상대방의 다음 숫자(더 작은 숫자)를 승리할 기회를 상실할 수도 있기 때문에(상실할 수도, 그렇지 않을 수도 있음)
// 매 결정시기마다 내가 가진 최대한 큰 숫자를 선택한다면, 이는 반드시 최적해의 부분해로 연결된다.(최적해는 유일하지 않음)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int sz = A.size();
    int idx_B=0;
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    
    for(int i=0;i<sz;i++) {
        if(A[i]>=B[idx_B])  continue;

        answer++;
        idx_B++;
    }
    return answer;
}
