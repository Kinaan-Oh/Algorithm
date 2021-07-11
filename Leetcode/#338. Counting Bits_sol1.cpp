// "Brian Kernighan 알고리즘", Time Complexity: O(nlgn), Space Complexity: O(1)
// Brian Kernighan 알고리즘을 통해 최적화.

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i=0;i<=n;i++) {
            int cnt=0;
            int j = i;
            while(j) {
                j &= (j-1);
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
