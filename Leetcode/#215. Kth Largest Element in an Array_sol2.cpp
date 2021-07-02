// "BST", Time Complexity: O(nlgn), Space Complexity: O(n) (n: nums.size)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int>    bst;
        for(int i=0;i<nums.size();i++) {
            bst.insert(nums[i]);
        }
        auto it = bst.end();
        for(int i=0;i<k;i++)    it--;
        return *it;
    }
};
