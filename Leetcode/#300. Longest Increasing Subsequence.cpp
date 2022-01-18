// DP, Time Complexity: O(n^2), Space Complexity: O(n) (n: nums.size)
// dp[i] : length of longest subsequence including nums[i] in the end
// 점화식: dp[i] = max(1, dp[k]+1) (0<=k<i, k: integer)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        int answer = 0;
        
        fill(&dp[0], &dp[n], 1);
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[j]<nums[i])    dp[i] = max(dp[i], dp[j]+1);
            }
            answer = max(answer, dp[i]);
        }
        return answer;
    }
};
