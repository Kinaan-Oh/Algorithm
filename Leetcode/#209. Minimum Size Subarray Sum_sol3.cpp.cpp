// Lower Bound(Binary Search)/Prefix Sum, Time Complexity: O(nlgn), Space Complexity: O(n) (n: nums.size)
// nums[i]>=1 조건으로 sum은 monotone increasing하고 binary search를 사용할 수 있는 이유가 된다.
// nums의 각 원소를 시작으로 하는 최소구간을 lower bound를 통해 O(lgn)으로 탐색할 수 있다.
// 탐색을 n회 반복하므로 전체 time complexity는 O(nlgn).

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n+1, 0);
        int answer = INT_MAX;
        
        for(int i=1;i<=nums.size();i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }
        for(int i=1;i<sum.size();i++) {
            int fnd = sum[i-1] + target;
            auto pos = lower_bound(sum.begin(), sum.end(), fnd);
            
            if(pos != sum.end()) {
                answer = min(answer, (int)distance(sum.begin()+i,pos+1));
            }
        }
        
        return answer == INT_MAX ? 0 : answer;
    }
};
