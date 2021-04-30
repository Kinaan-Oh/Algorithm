// N사 1차 면접에서 출제된 문제. Resursive DP. Time Complexity: O(n^2), Space Complexity: O(n).

class Solution {
private:
    int dp[20];  // idx: 0~19
public:
    int numTrees(int n) {
        if(n==0)    return dp[0]=1;
        if(dp[n])   return dp[n];
        
        for(int i=0;i<n;i++) {
            dp[n] += numTrees(i)*numTrees(n-1-i);
        }
        return dp[n];
    }
};
