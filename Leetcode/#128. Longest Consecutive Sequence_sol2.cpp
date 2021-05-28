// 출제의도: "해시테이블", Time Complexity: O(n), Space Complexity: O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_map<int,bool>  ht;
        unordered_map<int,bool> visited;
        for(int i=0;i<nums.size();i++)  ht[nums[i]]=true;
        for(int i=0;i<nums.size();i++) {
            if(!ht[nums[i]-1] && !visited[nums[i]]) {
                visited[nums[i]] = true;
                int cnt=1;
                int front = nums[i];
                while(ht[front+1]) {
                    front++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
