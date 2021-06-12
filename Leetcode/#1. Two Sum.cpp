// 출제의도: "Hash Table", Time Complexity: O(n), Space Complexity: O(n). (n: nums.size)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>  ht; // [num:index]
        for(int i=0;i<nums.size();i++) {
            if(ht.find(target-nums[i])!=ht.end()) {
                return {i,ht[target-nums[i]]};
            }
            ht[nums[i]] = i;
        }
        return {-1,-1};
    }
};
