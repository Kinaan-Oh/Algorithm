// 출제의도: "String, DP", Time Complexity: O(n^3), Space Complexity: O(n). (n: s.length)
// <점화식>
// dp[i]: 0~i까지 최대 팰린드롬의 길이 라고 할 때,
// dp[i] = max(dp[i-1], i번째 문자로 생성되는 팰린드롬의 최대 길이)

#include <iostream>
#include <string>

using namespace std;

int dp[2500];   // dp[i]: 0~i까지 최대 팰린드롬의 길이

int solution(string s)
{
    int answer=0;
    int sz = s.size();
    dp[0] = 1;
    for(int i=1;i<sz;i++) {
        for(int j=0;j<=i;j++) {
            int left=j, right=i;
            bool is_palindrome=true;
            while(left<right) {
                if(s[left]!=s[right]) {
                    is_palindrome=false;
                    break;
                }
                left++, right--;
            }
            if(is_palindrome) {
                dp[i]= max(dp[i-1], i-j+1);
                break;
            }
        }
    }
    answer = dp[sz-1];
    return answer;
}
