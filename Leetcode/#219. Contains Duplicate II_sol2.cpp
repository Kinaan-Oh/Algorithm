// Sliding Window, Time Complexity: O(nlgk), Space Complexity: O(k) (n: nums.size)
// Kakao에 출제된 문제

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int>  bst;
        
        for(int i=0;i<nums.size();i++) {
            if(bst.find(nums[i]) != bst.end())  return true;
            
            bst.insert(nums[i]);
            if(i>=k)    bst.erase(bst.find(nums[i-k]));
        }
        return false;
    }
};
