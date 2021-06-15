// "Brute Force", Time Complexity: O(n^2), Space Complexity: O(1). (n: height.size)
// idea: 전체 height의 trap을 구하는 문제를 "부분 문제로 분할"하여 각 height의 trap을 n번 반복하여 구하여 더한다.
// 비효율적인 코드임에도 sol1보다 문제를 바라보는 관점을 떠올리기 힘들었음.

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        
        for(int i=0;i<height.size();i++) {
            int left_max=0, right_max=0;
            
            for(int j=i-1;j>=0;j--) {
                left_max = max(left_max,height[j]);
            }
            for(int j=i+1;j<height.size();j++) {
                right_max = max(right_max,height[j]);
            }
            
            ans = min(left_max,right_max)-height[i]>=0 ? ans+min(left_max,right_max)-height[i] : ans;
        }
        return ans;
    }
};
