// "Two-pointer", Time Complexity: O(nlgn), Space Complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>   sorted;
        for(int i=0;i<nums.size();i++)  sorted.push_back({nums[i],i});
        sort(sorted.begin(),sorted.end());
        int left=0, right=sorted.size()-1;
        while(left<right) {
            if(sorted[left].first+sorted[right].first<target) {
                left++;
            }
            else if(sorted[left].first+sorted[right].first>target) {
                right--;
            }
            else    return {sorted[left].second,sorted[right].second};
        }
        return {-1,-1};
    }
};
