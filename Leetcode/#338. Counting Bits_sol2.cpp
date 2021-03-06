// "DP", Time Complexity: O(n), Space Complexity: O(n)
// most significant bit로 부분 문제로 분할. 
// 점화식: memo[n] = memo[n-cur]+1(cur: most significant bit).

class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0)    return {0};
        
        vector<int> memo(n+1,0);
        memo[0] = 0, memo[1] = 1;
        int cur = (1<<1);
        
        for(int i=2;i<=n;i++) {
            cur = i&(cur<<1) ? cur<<1 : cur;
            memo[i] = memo[i-cur]+1;
        }
        
        return memo;
    }
};
