// Time Complexity: O(nlgn), Space Complexity: O(1).
// 정렬 후, 최대 연속 수열 길이를 업데이트.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        int ans=0;
        int cnt=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++) {
            if(nums[i]-nums[i-1]>1) {
                ans = max(ans,cnt);
                cnt=1;
            }
            else if(nums[i]-nums[i-1]==1)   cnt++;
        }
        ans = max(ans,cnt);
        return ans;
    }
};
