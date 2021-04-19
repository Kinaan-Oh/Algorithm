class Solution {
    
    private:
        vector<vector<int>> powerSet;

    public:
        vector<vector<int>> subsets(vector<int>& nums) 
        {
            vector<int> cur;
            backtrack(0,cur,nums);
            return powerSet;
        }

        void backtrack(int start, vector<int> &cur, vector<int>& nums)
        {
            powerSet.push_back(cur);
            
            for(int i=start;i<nums.size();i++)
            {
                cur.push_back(nums[i]);
                backtrack(i+1,cur,nums);
                cur.pop_back();
            }
        }
};
