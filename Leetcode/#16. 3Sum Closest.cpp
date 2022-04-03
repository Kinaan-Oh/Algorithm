// Two-Pointer, Time Complexity: O(n^2), Space Complexity: O(1) (n: nums.size)
// 논리: 3Sum의 target 탐색경로의 모든 diff중 최소값을 memoize. answer -> target-diff(min)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size();i++) {
            int p1 = i+1;
            int p2 = nums.size()-1;

            while(p1<p2) {
                int sum = nums[i] + nums[p1] + nums[p2];

                if(abs(target-sum)<abs(diff)) {
                    diff = target-sum;
                }

                if(sum<target) {
                    p1 += 1;
                } else {
                    p2 -= 1;
                }
            }
        }
        return target-diff;
    }
};
