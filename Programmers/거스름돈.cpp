// 출제의도: "DP", Time Complexity: O(mn), Space Complexity: O(mn). (m: money.size)
// < 점화식 >
// dp[i][j] = dp[i-1][j]                       (money[i]>k)
//          = dp[i][j-money[i]] + dp[i-1][j]   (money[i]<=k)
// [주의 사항]
// 1) 동일한 종류의 동전은 여러번 선택할 수 있으므로 dp[i][j-money[i]]에서 i가 된다.
// 2) 0원을 만들 수 있는 경우의 수는 1이다.(모든 종류의 동전을 0개 선택)

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[100][100000]; // dp[i][j] : 0~i번째 화폐를 사용하여 j원을 만드는 경우의 수

int solution(int n, vector<int> money) {
    int answer = 0;
    for(int j=0;j<=n;j++) {
        dp[0][j] = j<money[0] ? 0 : (j%money[0]==0 ? 1 : 0);
    }
    for(int i=0;i<money.size();i++) {
        dp[i][0] = 1;
    }
    for(int i=1;i<money.size();i++) {
        for(int j=0;j<=n;j++) {
            dp[i][j] = money[i]>j ? dp[i-1][j] : dp[i][j-money[i]]+dp[i-1][j]; 
        }
    }
    answer = dp[money.size()-1][n];
    return answer;
}
