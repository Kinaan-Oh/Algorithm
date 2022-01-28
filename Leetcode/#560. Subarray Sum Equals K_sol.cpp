// Prefix Sum/DP/Math , Time Complexity: O(l), Space Complexity: O(l). (l: nums.size)
// dp는 0~i까지의 함을 memoize.
// i번째 원소를 마지막으로 하는 continuous subarray 중 합이 k를 만족하는 subarray 갯수를 구하는 것은,
// sum[i]를 0~i 원소합이라 할 때, sum[i] - sum[j] = k (j>=0 && j<i) 를 만족하는 j의 갯수를 구하는 것과 같다.
// sum[i] = sum[j] = k <-> sum[j] = sum[i] - k 이고 j<i 이므로, 원하는 답은 dp[sum[j]] 가 된다. (j<i이므로 이미 memoize되어 있다.)
 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int answer = 0;
        int sum = 0;
        unordered_map<int, int>    dp;  // [sum: num]
        
        dp[0] = 1;
        
        for(auto num: nums) {
            sum += num;

            if(dp.find(sum-k) != dp.end())  answer += dp[sum-k];
            dp[sum] += 1;
        }
        return answer;
    }
};
