// 출제의도: "DP", Time Complexity: O(n^2), Space Complexity: O(n^2). (n: s.length)
// 다음과 같은 팰린드롬의 성질에 주목: i+1~j-1 부분문자열이 팰린드롬이고 s[i]==s[j]이면 i~j 부분문자열이 팰린드롬이다.
// 따라서 i~j 부분문자열이 팰린드룸임을 확인하기 위해서는 보다 작은 부분 문자열 i+1~j-1이 팰린드롬인지 메오이제이션(memoization)을 이용하여 기록해놓았어야 한다.
// 길이가 짧은 부분문자열에서 긴 문자열 순으로 팰린드룸인지 확인하면서 메모이제이션(memoizatoin)한다면 bottom-up으로 Time Complexity O(n^2)으로 문제해결이 가능하다.

#include <iostream>
#include <string>

using namespace std;

bool dp[2500][2500]; // dp[i][j]: i~j인 부분문자열이 팰린드롬인지

int solution(string s)
{
    int answer=1;
    int sz = s.size();
    for(int i=0;i<sz;i++)   dp[i][i] = true;
    for(int i=0;i<sz-1;i++) {
        if(s[i]==s[i+1])    {
            dp[i][i+1] = true;
            answer = max(answer, 2);
        }
    }
    for(int i=3;i<=sz;i++) {
        for(int j=0;j+i-1<sz;j++) {
            if(s[j]==s[j+i-1] && dp[j+1][j+i-2]) {
                dp[j][j+i-1] = true;
                answer = max(answer, i);
            }
        }
    }

    return answer;
}
