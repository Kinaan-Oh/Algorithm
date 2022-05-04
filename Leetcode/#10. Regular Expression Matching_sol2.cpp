// DP(Top-Down)

class Solution {
private:
    int memo[21][31];
public:
    bool isMatch(string s, string p) {
        fill(&memo[0][0], &memo[20][30]+1, INT_MIN);
        return isMatch(0, 0, s, p);
    }
    
    bool isMatch(int i, int j, string s, string p) {
        if(memo[i][j]!=INT_MIN)  return memo[i][j];
        
        int answer;
        
        if(j == p.length())    answer = i == s.length();
        else {
            bool fistMatch = (i<s.length() && (s[i] == p[j] || p[j] == '.'));  

            if(j+1<p.length() && p[j+1] == '*') {
                answer = (isMatch(i, j+2, s, p) || (fistMatch && isMatch(i+1, j, s, p)));
            } else {
                answer = fistMatch && isMatch(i+1, j+1, s, p);
            }
        }
        
        memo[i][j] = answer ? 1: 0;
        return memo[i][j];
    }
};
