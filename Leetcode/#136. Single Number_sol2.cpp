// "Math", Time Complexity: O(n), Space Complexity: O(n).
// 2(a+b+c) - (2*a+2*b+c) = c
// 수학적 개념을 이용한 방법이지만, 시간/공간 효율성은 sol1과 동일.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int>   hash_set;
        int sum_hs=0, sum=0;
        for(int i=0;i<nums.size();i++) {
            hash_set.insert(nums[i]);
            sum += nums[i];
        }
        for(auto it=hash_set.begin();it!=hash_set.end();it++) {
            sum_hs += *it;
        }
        return 2*sum_hs - sum;
    }
};
