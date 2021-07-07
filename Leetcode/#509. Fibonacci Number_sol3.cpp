// "DP-BottomUp", Time Complexity: O(n), Space Complexoty: O(n).
// 작은 Subproblem에서 큰 Subproblem순으로 해를 단 한번씩만 구함.

class Solution {
private:
    int f[31];
public:
    int fib(int n) {
        if(n==0 || n==1)    return n;
        
        f[0] = 0, f[1] = 1;
        for(int i=2;i<=n;i++) {
            f[i] = f[i-1] + f[i-2];
        }
        return f[n];
    }
};
