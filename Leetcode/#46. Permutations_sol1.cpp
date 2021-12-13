// 출제의도: backtrack
// next_permutation은 의미가 없기에, 단순한 풀이인 dfs 선택.
// dfs를 좀더 효율적으로 개선가능할 것으로 생각됨.
// next_permutation을 구현해 본적이 있기 때문에, 해당 구현 원리를 이용한 풀이 역시 가능할 것으로 생각됨.

class Solution {
private:
    vector<vector<int>> answer;
    unordered_set<int> visited;
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, {});
        return answer;
    }
    
    void dfs(vector<int> &nums, vector<int> prev) {
        if(prev.size() == nums.size()) {
            answer.push_back(prev);
            return;
        }

        prev.push_back(0);
        for(int i=0;i<nums.size();i++) {
            if(visited.find(nums[i]) == visited.end()) {
                visited.insert(nums[i]);
                prev.back() = nums[i];
                dfs(nums, prev);
                visited.erase(nums[i]);
            }
        }
    }
};
