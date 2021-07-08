// "Divide and Conquer", Time Complexity: O(nlgn), Space Complexity: O(lgn) (n: nums.size)

// [ Time Complexity 증명 ]
// Tn = 2*Tn/2 + n
// n = 2^k
// T2^k = 2*T2^k-1 + 2^k
// t2^k / 2^k = t2^k-1 / 2^k-1 + 1
// Gk = Gk-1 + 1
// Gk = (k-1)
// T2^k /2^k= 
// T2^k = k*2^k + 2^k
// Tn = nlgn + n = O(nlgn).

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size()-1);
    }
    
    int maxSubArray(vector<int>& nums, int begin, int end) {
        if(begin>end)   return INT_MIN;
        
        int mid = (begin+end)/2;
        
        int maxSumIncludingMid = maxSubArrayIncludingMid(nums, begin, end, mid);
        int leftMaxSum = maxSubArray(nums, begin, mid-1);
        int rightMaxSum = maxSubArray(nums, mid+1, end);
        
        return max(maxSumIncludingMid ,max(leftMaxSum, rightMaxSum));
    }
    
    int maxSubArrayIncludingMid(vector<int>& nums, int begin, int end, int mid) {
        int leftMaxSum = 0, rightMaxSum = 0;
        int cur = 0;
        
        for(int i=mid-1;i>=begin;i--) {
            cur += nums[i];
            leftMaxSum = max(leftMaxSum, cur);
        }
        
        cur = 0;
        for(int i=mid+1;i<=end;i++) {
            cur += nums[i];
            rightMaxSum = max(rightMaxSum, cur);
        }
        
        return (nums[mid] + leftMaxSum + rightMaxSum);
    }
};
