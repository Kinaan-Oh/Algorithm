// O(n*2^n)

class Solution {
private:
    vector<vector<int>> powerSet;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        for(int b=(1<<nums.size())-1;b>=0;b--)
        {
            vector<int> subset;
            for(int i=0;i<nums.size();i++)
            {
                if(b&(1<<(nums.size()-1-i)))
                {
                    subset.push_back(nums[i]);
                }
            }
            powerSet.push_back(subset);
        }
        return powerSet;
    }
};
