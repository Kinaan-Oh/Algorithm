// 출제의도: Sliding Window, Time Complexity: O(n), Space Complexity: O(1) (n: nums.size) 

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int answer = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;
        
        while(right<nums.size()) {
            sum += nums[right++];
            
            while(sum-nums[left]>=target && left<=right) {
                sum -= nums[left++];
            }
            if(sum>=target)    answer = min(answer, right-left);
        }
        return answer == INT_MAX ? 0 : answer;
    }
};
