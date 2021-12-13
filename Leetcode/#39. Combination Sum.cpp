// 출제의도: backtrack/중복 조합
// dfs를 이용하면 쉽게 풀이 가능.

class Solution {
private:
    vector<vector<int>> answer;
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, {}, 0, 0, target);
        return answer;
    }
    
    void dfs(vector<int>& candidates, vector<int> prev, int start, int sum, int target) {
        if(sum == target) {
            answer.push_back(prev);
            return;
        }
        
        prev.push_back(0);
        for(int i=start;i<candidates.size();i++) {
            if(sum+candidates[i] <= target) {
                prev.back() = candidates[i];
                dfs(candidates, prev, i, sum+candidates[i], target);
            }
        }
    }
};
