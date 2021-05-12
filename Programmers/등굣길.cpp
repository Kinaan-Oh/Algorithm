// 출제의도: "DP", 점화식: Di,j = Di-1,j + Di,j-1.(단 i<2 or j<2인 경우 D는 0, puddle인 경우 D는 0), Time Complexity: O(mn), Space Complexity: O(mn).

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    //n행m열
    int answer = 0;
    fill(&dp[0][0],&dp[0][0]+101*101,-1);
    for(int i=0;i<puddles.size();i++) {
        dp[puddles[i][1]][puddles[i][0]] = 0;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(i==1&&j==1) {
                dp[1][1] = 1;
                continue;
            }
            if(dp[i][j]) {
                dp[i][j] = i-1<1 ? 0 : dp[i-1][j] ;
                dp[i][j] += j-1<1 ? 0 : dp[i][j-1];
                dp[i][j] %= 1000000007;
            }
        }
    }
    answer = dp[n][m];
    return answer;
}
