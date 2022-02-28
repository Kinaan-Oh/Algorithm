// Two-Pointer, Time Complexity: O(n), Space Complexity: O(1). (n: nums.size)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>    answer(nums.size(), 0);
        int p = answer.size()-1;
        int left = 0;
        int right = nums.size()-1;
        
        while(left<=right) {
            if(abs(nums[left])<abs(nums[right])) {
                answer[p--] = nums[right]*nums[right];
                right -= 1;
            } else {
                answer[p--] = nums[left]*nums[left];
                left += 1;
            }
        }
        return answer;
    }
};
