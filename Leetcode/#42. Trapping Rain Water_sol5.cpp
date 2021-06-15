// "Two-Pointer", Time Complexity: O(n), Space Complexity: O(1).
// 2-Pass인 sol1을 투 포인터 기법을 이용하여 1-Pass로 개선하였다.

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left_max=0, right_max=0;
        int left=0, right=height.size()-1;
        
        while(left<right) {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            
            if(left_max<right_max) {
                ans += (left_max - height[left]);
                left++;
            }
            else {
                ans += (right_max - height[right]);
                right--;
            }
        }
        return ans;
    }
};
