// "Divide and Conquer", Time Complexity: O(nlgn), Space Complexity: O(lgn) (n: nums.size)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElementInPart(nums, 0, nums.size()-1);
    }
    
    int majorityElementInPart(vector<int>& nums, int begin, int end) {
        if(begin==end)  return nums[begin];
        
        int mid = (begin+end)/2;
        int left = majorityElementInPart(nums, begin, mid);
        int right = majorityElementInPart(nums, mid+1, end);
        
        if(left == right)   return left;
        return count(nums, begin, end, left)<count(nums, begin, end, right) ? right : left;
    }
    
    int count(vector<int>& nums, int begin, int end, int num) {
        int cnt = 0;
        for(int i=begin;i<=end;i++) {
            if(nums[i]==num)    cnt++;
        }
        return cnt;
    }
};
