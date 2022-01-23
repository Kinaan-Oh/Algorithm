// Brute-Force/Dfs, Time Complexity: O(2^n), Space Complexity: O(n) (n: nums.size)
// Time Limit Exceeded. 36 / 117 test cases passed..

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        
        for(auto num: nums)  target += num;
        if(target%2)  return false;
        target /= 2;
        return dfs(nums, target, 0, 0);
    }
    
    bool dfs(vector<int>& nums,int target, int sum, int end) {
        if(sum == target)   return true;
        else if(end == nums.size())  return false;
        
        bool ret = false;
        ret = dfs(nums, target, sum, end+1);
        if(ret) return true;
        
        ret = dfs(nums, target, sum+nums[end], end+1);
        if(ret) return true;
        
        return false;
    }
};
