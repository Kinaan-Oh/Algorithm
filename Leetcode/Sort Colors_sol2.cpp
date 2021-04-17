// Time Complexity: O(N), Space Complexity: O(1)
// 키 비교 연산으로 sol1과 비교하면 더 적지만, 메모리 접근 연산으로 비교하면 swap의 사용으로(3회) sol1보다 더 많음. 따라서, 실행시간은 sol1 보다 오래걸림.

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
