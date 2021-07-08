// "Recursion with Memoization", Time Compleixyt: O(n), Space Complexity: O(n)
// Fibonacci와 동일한 점화식. (f(n) = f(n-1) + f(n-2)).

class Solution {
private:
    int dp[46];
public:
    int climbStairs(int n) {
        if(dp[n])   return dp[n];
        if(n==1 || n==2)    return dp[n] = n;
        
        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};
