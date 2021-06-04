// 출제의도: "DP, 슬라이딩 윈도우", Time Complexity: O(mn), Space Complexity: O(n). (m: money.size)
// dp[i][j]를 갱신할 때 모든 i에 대해 값을 유지할 필요없고 바로 직전(dp[i-1][])만 필요함. 따라서, 1차원 배열만 유지하여 직전 값만 보존하는 방법을 시도해 볼 수 있음.
// 이 방법은 dp[i][j]를 차례대로 갱신할 때 필요한 1) dp[i][j-money[i]]이 갱신되어 있고, 2) 갱신전 정보 dp[i-1][j]이 보존되어야 한다는 전제조건이 필요함.
// 두 조건을 만족하므로 sol1의 Space Complexity를 O(n)으로 향상시킬 수 있음. 이러한 기법을 슬라이딩 윈도우 기법이라고들 함.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[100000]; // dp[i][j] : 0~i번째 화폐를 사용하여 j원을 만드는 경우의 수

// dp[i][j] = dp[i-1][j]                       (money[i]>k)
//          = dp[i][j-money[i]] + dp[i-1][j]   (money[i]<=k)

int solution(int n, vector<int> money) {
    int answer = 0;
    for(int j=0;j<=n;j++) {
        dp[j] = j<money[0] ? 0 : (j%money[0]==0 ? 1 : 0);
    }
    dp[0] = 1;
    
    for(int i=1;i<money.size();i++) {
        for(int j=0;j<=n;j++) {
            dp[j] = money[i]>j ? dp[j] : dp[j-money[i]]+dp[j]; 
        }
    }
    answer = dp[n];
    return answer;
}
