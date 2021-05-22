// 출제의도: "greedy", Time Complexity: O(n), Space Complexity: O(n).
// 여분의 옷을 가진 학생을 기준으로, 왼쪽에 나누어줄 수 있다면 우선적으로 분배(왼쪽의 학생에게 분배하지 않으면 왼쪽 학생은 옷을 받을 기회가 없음). 왼쪽에 나누어줄 수 없고 오른쪽에 나누어줄 수 있다면 오른쪽에 분배.
// 그리디 접근법이 성립하는 이유를 수학적으로 증명하지는 못했다.

#include <string>
#include <vector>

using namespace std;

int student[31];    // 1~30

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i=0;i<lost.size();i++) {
        student[lost[i]] -= 1;
    }
    for(int i=0;i<reserve.size();i++) {
        student[reserve[i]] += 1;
    }
    for(int i=1;i<=n;i++) {
        if(student[i]==1) {
            int left = i-1, right = i+1;
            if(left>=1 && student[left]==-1) {
                student[left]++;
                student[i]--;
                continue;
            }
            
            if(right<=n && student[right]==-1) {
                student[right]++;
                student[i]--;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        if(student[i]>=0) {
            answer++;
        }
    }
    return answer;
}
