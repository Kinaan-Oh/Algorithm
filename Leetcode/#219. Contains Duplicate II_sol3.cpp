// Sliding Window/Hash Set, Time Complexity: O(n), Space Complexity: O(k)
// sol2의 bst의 find time complexity O(lgk)를 hashset을 이용하여 O(1)로 개선.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>  hashset;
        
        for(int i=0;i<nums.size();i++) {
            if(hashset.find(nums[i]) != hashset.end())  return true;
            
            hashset.insert(nums[i]);
            if(i>=k)    hashset.erase(hashset.find(nums[i-k]));
        }
        return false;
    }
};
