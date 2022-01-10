// Greedy, Time Complexity: O(n), Space Complexity: O(1) (n: nums.size)
// sol2의 논리를 따름.
// 다만, i에서 목적지에 도달가능한 j(i<j)는 목적지에 도달가능한 집합 중 최소값만 있어도 된다. 따라서, 목적지에 도달 가능한 최소 index 를 유지하여 문제를 해결할 수 있다.
// 따라서, 목적지에 도달가능한 최소 index를 지속적으로 update 한다는 점에서 Greedy한 접근이라 볼 수 있다.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int isPossible = nums.size()-1;
        
        for(int i=nums.size()-2;i>=0;i--) {
            if(i+nums[i]>=isPossible) {
                isPossible = i;
            }
        }
        return  isPossible == 0;
    }
};
