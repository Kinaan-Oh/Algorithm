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

// ReDo 2022/03/12 Combination/Backtrack, Time Complexity: O(nCk), Space Complexity: O(k)
// 중복선택이 가능함을 반영하는 것이 관건.

class Solution {
private:
    vector<vector<int>> answer;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, {}, 0, 0, target);
        return answer;
    }
    
    void dfs(vector<int>& candidates, vector<int> prev, int start, int curSum, int target) {
        if(curSum==target) {
            answer.push_back(prev);
            return;
        } else if(curSum>target) {
            return;
        }
        
        prev.push_back(0);
        for(int i=start;i<candidates.size();i++) {
            prev.back() = candidates[i];
            dfs(candidates, prev, i, curSum+candidates[i], target);
        }
    }
};
