// Time Complexity = O(2*N)->O(N), Space Complexity = O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> ht;
        for(int i=0;i<nums.size();i++)  ht[nums[i]]++;
        int idx=0;
        for(int i=0;i<ht[0];i++)   nums[idx++]=0;
        for(int i=0;i<ht[1];i++)   nums[idx++]=1;
        for(int i=0;i<ht[2];i++)   nums[idx++]=2;
    }
};
