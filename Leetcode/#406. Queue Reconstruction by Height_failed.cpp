// "Brute Force", Time Complexity: O(n^3), Space Complexity: O(n). (n: people.size)

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        
        for(int i=0;i<people.size();i++) {
            vector<int> next = {INT_MAX,INT_MAX};
            for(int j=0;j<people.size();j++) {
                if(satisfyConstraint(ans, people[j]) && next[0]>people[j][0]) {
                    next = people[j];
                }
            }
            ans.push_back(next);
        }
        
        return ans;
    }
    
    bool satisfyConstraint(vector<vector<int>> &ans, vector<int> &person) {
        int peopleHaveHeightGreaterOrEqualTo = 0;
        for(int i=0;i<ans.size();i++) {
            if(ans[i][0]>=person[0])   peopleHaveHeightGreaterOrEqualTo++;
        }
        return peopleHaveHeightGreaterOrEqualTo==person[1];
    }
};
