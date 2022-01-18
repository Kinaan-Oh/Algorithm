// 출제의도: DP, Time Complexity: O(mn), Space Complexity: O(m) (m: amount, n: coins.size)
// dp[i] : i원을 만들 수 있는 최소 동전 갯수
// 점화식 : dp[i] = min(dp[k]+1) (dp[k]>=0, k: i-some coin, k>=0)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        
        fill(&dp[0], &dp[amount+1], -1);
        for(int i=0;i<coins.size();i++)   if(coins[i]<=amount)  dp[coins[i]] = 1;
        dp[0] = 0;
        
        for(int i=0;i<=amount;i++) {
            for(int j=0;j<coins.size();j++) {
                int left = i-coins[j];
                
                if(left>=0 && dp[left]>=0) {
                    if(dp[i]<0)    dp[i] = dp[left]+1;
                    else    dp[i] = min(dp[i], dp[left]+1); 
                }
            }
        }
        return dp[amount];
    }
};
