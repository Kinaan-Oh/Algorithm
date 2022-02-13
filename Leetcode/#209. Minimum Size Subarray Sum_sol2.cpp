// Prefix Sum, Time Complexity: O(n^2), Space Complexity: O(n) (n: nums.size)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int prefixSum[n+1];
        int answer = INT_MAX;
        
        fill(&prefixSum[0], &prefixSum[n]+1, 0);
        for(int i=0;i<nums.size();i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
        
        for(int i=1;i<=nums.size();i++) {
            for(int j=i;j<=nums.size();j++) {
                if(prefixSum[j]-prefixSum[i-1]>=target) {
                    answer = min(answer, j-i+1);
                }
            }
        }
        return answer == INT_MAX ? 0 : answer;
    }
};
