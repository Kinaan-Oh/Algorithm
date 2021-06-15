// "DP", Time Complexity: O(n), Space Complexity: O(n).
// sol2의 left_max, right_max을 미리 구하여 memoize 한다.

class Solution {
private:
    int left_max[30000];
    int right_max[30000];
    
public:
    int trap(vector<int>& height) {
        int ans = 0;
        fill(&left_max[0],&left_max[0]+30000,0);
        fill(&right_max[0],&right_max[0]+30000,0);
        
        for(int i=1;i<height.size();i++) {
            left_max[i] = max(height[i-1],left_max[i-1]);
        }
        for(int i=height.size()-2;i>=0;i--) {
            right_max[i] = max(height[i+1],right_max[i+1]);
        }
        
        for(int i=0;i<height.size();i++) {
            ans = min(left_max[i],right_max[i])-height[i]>=0 ? ans+min(left_max[i],right_max[i])-height[i] : ans;
        }
        return ans;
    }
};
