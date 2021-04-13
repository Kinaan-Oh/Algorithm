class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        for(int i=0;i<=right;i++)
        {
            switch(nums[i])
            {
                case 0:
                    swap(nums[left],nums[i]);
                    left++;
                    break;
                    
                case 2:
                    swap(nums[right],nums[i]);
                    right--;
                    i--;
                    break;
            }
        }  
    }
};
