// Math/Sort, Time Complexity: O(nlgn), Space Complexity: O(1) (n: nums.size)
// 논리: nums는 nagative를 포함할 수 있으므로, nums[0]*nums[1]*nums[n-1]도 정답의 후보가 된다.

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        return max(nums[0]*nums[1]*nums[n-1], nums[n-3]*nums[n-2]*nums[n-1]);
    }
};
