// dfs with memoization, Time Complexity: O(n^2), Space Complexity: O(n) (n: nums.size)
// 정답을 발견하는 즉시 탐색종료해야 Time Limit 내에 통과.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> visited(nums.size(),false);
        visited[0] = true;
        return dfs(nums, visited, 0);
    }
    
    bool dfs(vector<int>& nums, vector<bool>& visited, int cur) {
        if(cur==nums.size()-1)  return true;
        
        bool isPossible = false;
        
        for(int i=1;i<=nums[cur];i++) {
            if(cur+i<nums.size() && !visited[cur+i]) {
                visited[cur+i] = true;
                isPossible = dfs(nums, visited, cur+i);
                
                if(isPossible)  return true;
            }
        }
        return false;
    }
};
