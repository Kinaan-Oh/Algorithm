// C++ next_permutation에 구현된 방법으로 구현. Time Complexity: O(n), Space Complexity: O(1) (n: nums.size)
// 카카오 2020 인턴 수식 최대화 문제 풀이시 직접 구현해본 경험이 있음.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1)  return;
        
        int n = nums.size()-2, m = 0;
        while(n>=0 && !(nums[n]<nums[n+1])) { 
            n--; 
        }
        if(n==-1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int i=n+1;i<nums.size();i++) {
            if(nums[i]>nums[n]) m = max(m, i);
        }
        swap(nums[n], nums[m]);
        reverse(nums.begin()+n+1,nums.end());
    }
};
