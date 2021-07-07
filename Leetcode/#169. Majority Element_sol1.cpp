// "Hash Table", Time Complexity: O(n), Space Complexity: O(n) (n: nums.size)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>  ht;
        int n = nums.size();
        for(int i=0;i<n;i++)  {
            ht[nums[i]]++;
            if(ht[nums[i]]>n/2)    return nums[i];
        }
        return -1;
    }
};
