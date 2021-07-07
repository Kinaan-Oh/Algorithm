// "Divide and Conquer", Time Complexity: O(nlgn), Space Complexity: O(lgn) (n: nums.size)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;
        int sum = 0;
        for(int i=0;i<nums.size();i++) {
            if(sum==0) {
                candidate = nums[i];
            }
            
            sum += (nums[i]==candidate ? 1 : -1);
        }
        
        return candidate;
    }
};
