// Binary Search(Recursion), Time Complexity: O(lgn), Space Complexity: O(1) (n: nums.size)
// master theorem에 의해 T(n) = T(n/2) + 1 -> T(n) = lgn.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size(), target);
    }
    
    int search(vector<int>& nums, int begin, int end, int target) {
        if(begin>=end)   return -1;
        int mid = (begin+end)/2;
        
        if(nums[mid]>target)    return  search(nums, begin, mid, target);
        else if(nums[mid]<target)   return search(nums, mid+1, end, target);
        else    return  mid;
    }
};
