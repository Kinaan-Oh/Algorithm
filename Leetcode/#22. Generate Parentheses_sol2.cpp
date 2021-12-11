// BackTrack, Time Complexity: O(4^n/n^3/2), Space Complexity: O(4^n/n^3/2).
// 전형적인 Catalan Number 문제.
// 점화식: Cn = C0*Cn-1 + C1*Cn-2 + .. + Cn-2*C1 + Cn-1*C0.
// Stirling’s approximation에 의해 Time Complexity는 4^n/n^3/2 로 근사된다.

class Solution {
private:
    vector<string> answer;
    
public:
    vector<string> generateParenthesis(int n) {
        backtrack("", n, 0, 0);
        
        return answer;
    }
    
    void backtrack(string parenthesis, int n, int left, int right) {
        if (parenthesis.length() == 2*n) {
            answer.push_back(parenthesis);
            return;
        }
        
        if (left<n) {
            backtrack(parenthesis+"(", n, left+1, right);
        }
        if (right<n && left>right) {
            backtrack(parenthesis+")", n, left, right+1);
        }
    }
};
