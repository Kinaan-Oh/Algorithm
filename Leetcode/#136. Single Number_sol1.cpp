// "Hash Table", Time Complexity: O(n), Space Complexity: O(n).

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>  ht;
        for(int i=0;i<nums.size();i++) {
            ht[nums[i]]++;
        }
        for(auto it=ht.begin();it!=ht.end();it++) {
            if(it->second==1)   return it->first;
        }
        return INT_MIN;
    }
};
