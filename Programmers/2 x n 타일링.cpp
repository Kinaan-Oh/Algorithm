// timeComplexity: O(n), spaceComplexity: O(n)
// 피보나치 점화 관계: 길이가 n인 2Xn 타일은 case1) 길이 n-1인 2Xn타일에 길이 1인 타일 1개를 붙이거나, case2) 길이 n-2인 2Xn 타일에 길이 2인 타일 2개를 붙여 만들 수 있음. f(n) = f(n-1) + f(n-2).

#include <string>
#include <vector>

using namespace std;

int dp[60001];

int fibonacci(int n)
{
    if(dp[n])   return dp[n];
    return dp[n] = (fibonacci(n-1) + fibonacci(n-2)) % 1000000007;
}

int solution(int n) {
    int answer = 0;
    dp[1] = 1;
    dp[2] = 2;
    answer = fibonacci(n);
    return answer;
}
