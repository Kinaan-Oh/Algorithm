// "Greedy, Two-Pointer", Time Complexity: O(n), Space Complexity: O(1) (n: height.size)
// width가 최대(left=0, right=height.size()-1, width:height.size-1) 구간을 시작점으로 하여 하위 구간 width-1, width-2, ... , 1 방향으로 탐색한다.
// height[left] < height[right] 일 때, right을 왼쪽으로 이동시키면 area는 기존보다 작거나 같아진다. 반면, left를 우측으로 이동하면 area는 기존보다 작아질수도 같을수도 커질수도 있다.
// 따라서, 위 경우 area의 최대값을 찾기위해 right를 이동시키는 것은 전혀 유망하지 않으므로 left를 이동한다.
// 정리하면, left, right 중 높이가 작은 것을 이동시키면서 탐색하면서 area를 갱신하고(area는 갱신될 수도 안될수도 있다.) width가 1이 된다면 종료한다.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left=0, right=height.size()-1;
        
        while(left<right) {
            ans = max(ans, (right-left)*min(height[left],height[right]));
            if(height[left]<height[right])  left++;
            else    right--;
        }
        return ans;
    }
};
