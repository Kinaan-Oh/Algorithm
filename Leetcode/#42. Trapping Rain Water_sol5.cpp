// "Two-Pointer", Time Complexity: O(n), Space Complexity: O(1).
// 2-Pass인 sol1을 투 포인터 기법을 이용하여 1-Pass로 개선하였다.

// 2022/02/07 ReDo : DP sol을 Two-Pointer 기법을 이용해 1-Pass, Space Complexity O(1) 로 개선.

class Solution {
public:
    int trap(vector<int>& height) {
        int answer = 0;
        int left = 0;
        int right = height.size()-1;
        int maxLeftHeight = height.front();
        int maxRightHeight = height.back();
        
        while(left<right) {
            if(maxLeftHeight<maxRightHeight) {
                answer += (maxLeftHeight-height[left++]);
                maxLeftHeight = max(maxLeftHeight, height[left]);
            } else {
                answer += (maxRightHeight-height[right--]);
                maxRightHeight = max(maxRightHeight, height[right]);
            }
        }
        return answer;
    }
};
