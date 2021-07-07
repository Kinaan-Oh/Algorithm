// "DP(Memoization)-TopDown", Time Complexity: O(n), Space Complexity: O(n).
// Overlapping Subproblem을 Memoization을 통해 단 한번씩만 푼다.

class Solution {
private:
    int f[31];
    
public:
    int fib(int n) {
        if(f[n])    return f[n];
        if(n==0 || n==1)    return f[n] = n;
        
        return f[n] = fib(n-1) + fib(n-2);
    }
};
