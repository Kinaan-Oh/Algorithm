class Solution {
private:
    vector<vector<int>> combination;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        backtrack(n,k,0,cur);
        return combination;
    }
    
    void backtrack(int n, int k, int start, vector<int> cur)
    {
        if(cur.size()==k)
        {
            combination.push_back(cur);
            return;
        }
        
        for(int i=start+1;i<=n;i++)
        {
            cur.push_back(i);
            backtrack(n,k,i,cur);
            cur.pop_back();
        }
    }
};

// Redo 2022/03/12. Combination/DFS, Time Complexity: O(nCk), Space Complexity: O(k)

class Solution {
private:
    vector<vector<int>> answer;
public:
    vector<vector<int>> combine(int n, int k) {
        dfs({}, 1, n, k);
        return answer;
    }
    
    void dfs(vector<int> prev, int start, int n, int k) {
        if(prev.size()==k) {
            answer.push_back(prev);
            return;
        }
        
        for(int i=start;i<=n;i++) {
            vector<int> cur = prev;
            cur.push_back(i);
            dfs(cur, i+1, n, k);
        }
    }
};
