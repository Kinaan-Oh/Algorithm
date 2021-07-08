// "Bottom-up DP", Time Complexity: O(n), Space Complexity: O(n).
// 점화식: 0~n 집을 털어 얻을 수 있는 최대값 = max( n번째 집에 숨겨진 돈 + 0~n-2 집을 털어 얻을 수 있는 최대값(n번째 집을 택하면 n-1번째 집은 택할 수 없음) , 
// 0~n-1 집을 털어 얻을 수 있는 최대값(n번째 집을 택하지 않으면 0~n-1집을 터는 문제와 같음) )
// 문제의 크기를 0~i 번째 집으로 정의. 0~i+1은 0~i에서 i+1번째 집을 추가로 고려한 바로 한 단계 크기 위의 문제.

class Solution {
private:
    int dp[100];
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)    return nums[0];
        
        dp[0] = nums[0], dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};
