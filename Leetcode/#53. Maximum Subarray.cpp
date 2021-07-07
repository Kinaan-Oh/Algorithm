// "Kadane의 알고리즘", Time Complexity: O(n), Space Complexity: O(1).
// idea: subArray의 합이 음수가 되면, 배열의 다음 원소를 새로운 시작점으로 subArray를 계산한다.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        for(int i=0;i<nums.size();i++) {
            sum = sum<0 ? nums[i] : sum+nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};
