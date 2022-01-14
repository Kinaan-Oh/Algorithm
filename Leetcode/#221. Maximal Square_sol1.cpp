// Brute-Force, Time Complexity: O(m^2n^2), Space Complexity: O(1). (m: matrix.size, n:matrix[0].size)
// Time Limit Exceeded: 75 / 77 test cases passed.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max_length = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]=='0')    continue;
                
                int l = 2;
                bool is_possible = true;
                
                while(i-l+1>=0 && j-l+1>=0) {
                    for(int k=0;k<l;k++) {
                        if(matrix[i-l+1][j-l+1+k]=='0' || matrix[i-l+1+k][j-l+1]=='0')  {
                            is_possible = false;
                            break;
                        }
                    }
                    
                    if(!is_possible)    break;
                    l += 1;
                }
                max_length = max(max_length, l-1);
            }
        }
        return max_length * max_length;
    }
};
