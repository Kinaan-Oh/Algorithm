// 출제의도: Binary Search. Time Complexity: O(lgn), Space Complexity: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return b_search(nums, 0, nums.size(), target);
    }
    
    int b_search(vector<int>& nums, int begin, int end, int target) {
        if(begin==end)  return begin;
        
        int mid = (begin+end)/2;
        if(nums[mid]==target) {
            return mid;
        } else if(nums[mid]<target) {
            return b_search(nums,mid+1,end,target); 
        } else {
            return b_search(nums,begin,mid,target); 
        }
    }
};
