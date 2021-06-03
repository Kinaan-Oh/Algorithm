// 출제의도: "원형에서의 DP", Time Complexity: O(n), Space Complexity: O(n). (n: sticker.size)
// 원형에서의 DP를 선형에서의 DP로 변환하여 푼다.
// 만약, 선형 배열에서의 DP였다면 해당 점화식으로 쉽게 해결할 수 있었지만, 원형이라는 제약조건으로 인해 처음과 마지막 스티커는 동시에 선택 될 수가 없다.
// 따라서, 1) 첫번째 스티커를 선택한 경우 2) 첫번째 스티커를 선택하지 않은 경우 로 나누어 접근한다. 1)의 경우 마지막 스티커를 고려하지 않는 최대값을 선택하고 2)는 마지막 스티커를 고려한 최대값을 선택한다.

#include <iostream>
#include <vector>

using namespace std;

int dp[100000];
// dp[i]: 0~i까지의 최대합
// dp[i] = max(dp[i-2]+sticker[i], dp[i-1])

int solution(vector<int> sticker)
{
    int answer = 0;
    int sz = sticker.size();
    if(sz==1)   return sticker[0];
    
    dp[0] = sticker[0], dp[1] = sticker[0];
    for(int i=2;i<sz;i++) {
        dp[i] = max(dp[i-2]+sticker[i], dp[i-1]);
    }
    answer = max(answer, dp[sz-2]);
    
    dp[0] = 0, dp[1] = sticker[1];
    for(int i=2;i<sz;i++) {
        dp[i] = max(dp[i-2]+sticker[i], dp[i-1]);
    }
    answer = max(answer, dp[sz-1]);
    return answer;
}
