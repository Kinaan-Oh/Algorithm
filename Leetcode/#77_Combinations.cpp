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
