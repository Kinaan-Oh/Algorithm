// Two-Pointer, Time Complexity: O(n), Space Complexity: O(1). (n: nums.size)
// Two-Pointer를 이용한 reverse 기법을 이미 알고있었고, reverse를 이용하여 rotate를 구현할 수 있었다.
// Space Complexity O(1) 조건이 없다면, 추가 배열을 생성하여 쉽게 구현 가능. 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums, 0, nums.size());
        reverse(nums, 0, k%nums.size());
        reverse(nums, k%nums.size(), nums.size());
    }
    
    void reverse(vector<int>& nums, int begin, int end) {
        while(begin<end-1) {
            swap(nums[begin], nums[end-1]);
            begin += 1;
            end -= 1;
        }
    }
};
