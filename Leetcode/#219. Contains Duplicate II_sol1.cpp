// Hash Table, Time Complexity: O(n), Space Complexity: O(n) (n: nums.size)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>    ht; // [num:index]
        
        for(int i=0;i<nums.size();i++) {
            if(ht.find(nums[i]) == ht.end()) {
                ht[nums[i]] = i;
                continue;
            }    
            
            if(abs(ht[nums[i]]-i)<=k)   return true;
            ht[nums[i]] = i;
        }
        return false;
    }
};
