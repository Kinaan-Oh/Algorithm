// Bottom-Up DP, Time Complexity: O(n^2), Space Complexity: O(n) (n: nums.size)
// 논리: i<j 이고 j가 목적지에 도달가능하며 i가 j에 도달가능하다면 -> i는 목적지에 도달가능하다.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> isPossible(nums.size(),false);
        isPossible[nums.size()-1] = true;
        
        for(int i=nums.size()-2;i>=0;i--) {
            for(int j=i+1;j<=i+nums[i];j++) {
                if(j==nums.size())  break;
                if(isPossible[j]) {
                    isPossible[i] = true;
                    break;
                }
            }
        }
        return isPossible[0];
    }
};
