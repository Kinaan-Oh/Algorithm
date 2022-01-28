// prefix sum, Time Complexity: O(l^2), Space Complexity: O(l^2) (l: nums.size)
// Time Limit Exceeded, 85 / 89 test cases passed.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum[n];
        int answer = 0;
        
        sum[0] = nums[0];
        for(int i=1;i<nums.size();i++)  sum[i] = sum[i-1] + nums[i];
        
        for(int i=0;i<nums.size();i++) {
            for(int j=i;j<nums.size();j++) {
                if(i==0 && sum[j]==k)   answer += 1;
                else if(i && sum[j]-sum[i-1]==k)    answer += 1;
            }
        }
        return answer;
    }
};
