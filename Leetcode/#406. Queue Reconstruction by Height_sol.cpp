// "Greedy", Time Complexity: O(n^2), Space Complexity: O(n) (n: people.size)
// idea: 위치가 결정되지 않은 사람들중 키가 가장 작은 사람의 위치는 유일하게 결정된다.
// 이유: 키가 가장 작은 사람의 왼쪽에는 반드시 키가 보다 크거나 작은 사람만 위치한다.

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<int> EMPTY = {-1,-1};
        vector<vector<int>> ans(people.size(), EMPTY);
        sort(people.begin(), people.end());
        
        for(int i=0;i<people.size();i++) {
            int pos = 0, cnt = 0;
            for(int j=0;j<ans.size();j++) {
                if(ans[j]==EMPTY && cnt==people[i][1]) {
                    pos = j;
                    break;
                }
                cnt = (ans[j]==EMPTY || ans[j][0]==people[i][0] ? cnt+1 : cnt);
            }
            
            ans[pos] = people[i];
        }
        return ans;
    }
};
