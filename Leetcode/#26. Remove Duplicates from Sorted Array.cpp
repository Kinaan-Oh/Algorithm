// Two-Pointer, Time Complexity: O(n), Space Complexity: O(1) (n: nums.size)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p1 = 0;
        int p2 = 1;
        
        for(;p2<nums.size();p2++) {
            if(nums[p1]<nums[p2]) {
                nums[++p1] = nums[p2];
            }
        }
        return p1+1;
    }
};
