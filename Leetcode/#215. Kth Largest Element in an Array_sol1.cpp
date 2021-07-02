// "multi hash-set", Time Complexity: O(nlgn), Space Complexity: O(n). (n: nums.size)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unordered_multiset<int>  hash_set;
        sort(nums.begin(),nums.end(),greater<int>());
        
        for(int i=0;i<nums.size();i++) {
            if(hash_set.size()==k-1)    return nums[i];
            hash_set.insert(nums[i]);
        }
        return -1;
    }
};
