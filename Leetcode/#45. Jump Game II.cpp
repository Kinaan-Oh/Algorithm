// 출제의도: DP or Greedy, Time Complexity: O(n^2), Space Complexity: O(n) (n: nums.size)
// dp[i] : i번째에서 목적지로 가는 최소 점프 수 , dp[i] = min(i에서 도달가능한 지점들 j에 대해 1+dp[j])
// 목적지까지 경로가 반드시 존재한다는 특수한 문제조건 때문에, Greedy한 Approach도 가능하다. Time Complexity O(n)으로 DP보다 효율적이지만, 억지로 만들어낸 이 문제만을 위한 sol이라 범용적으로 쓰일 논리는 아닌 것 같다.
// 실제 microsoft 기술면접에서도 dp 만으로 통과되었으니, Greedy Approach는 기억만 하자.

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[nums.size()-1] = 0;
        
        for(int i=nums.size()-2;i>=0;i--) {
            for(int j=i+1;j<nums.size();j++) {
                if(i+nums[i]<j)    break;
                if(dp[j]!=INT_MAX)  dp[i] = min(dp[i], dp[j]+1);
            }
        }
        return dp[0];
    }
};
