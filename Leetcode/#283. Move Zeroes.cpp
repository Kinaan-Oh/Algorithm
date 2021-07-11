// "구현", Time Complexity: O(n), Space Complexity: O(1). (n: nums.size)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int front = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=0) {
                nums[front++] = nums[i];
            }
        }
        for(int i=front;i<nums.size();i++) {
            nums[i] = 0;
        }
    }
};
