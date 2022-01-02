// 출제의도: Binary Search, Time Complexity: O(lgn), Space Complexity: O(n) (n: nums.size)
// Recursion은 call stack을 worst case n개 쌓는다. 이는 iteration 방식으로 구현하면 O(1)로 개선할 수 있다.
// 첫원소와 비교하여 target의 위치를 추정하는 것이 문제해결의 핵심 idea였고 짧은 시간에 생각해내는 것은 쉽지 않았다. hint 없이는 시간이 걸릴 문제라고 판단.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size(), target);
    }
    
    int search(vector<int>& nums, int begin, int end, int target) {
        if(begin>=end)  return -1;
        
        int mid = (begin+end)/2;
        
        if(nums[mid] == target) return mid;
        else if(nums[mid]>=nums[begin]) {
            if(nums[mid]>target && target>=nums[begin]) return search(nums, begin, mid, target);
            else return search(nums, mid+1, end, target);
        } else {
            if(nums[mid]<target && target<nums[begin]) return  search(nums, mid+1, end, target);
            else return search(nums, begin, mid, target);
        }
    }
};
