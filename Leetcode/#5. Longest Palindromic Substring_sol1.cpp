// "DP - Bottom Up", Time Complexity: O(n^2), Space Complexity: O(n^2) (n: s.length)
// 점화식: 부분 문자열 i~j가 Palindrome이기 위해서는 1) s[i]==s[j] 이고 2) 부분 문자열 i+1~j-1가 Palindrome 이어야만 한다.

class Solution {
private:
    bool memo[1000][1000];
    
public:
    string longestPalindrome(string s) {
        vector<int> idx = {0,0};
        fill(&memo[0][0],&memo[0][0]+1000*1000,false);
        for(int i=0;i<s.length();i++)   memo[i][i] = true;
        for(int i=0;i<s.length()-1;i++) {
            if(s[i]==s[i+1]) {
                memo[i][i+1] = true;
                idx[0] = i, idx[1] = i+1;
            }
        }
        
        for(int l=3;l<=s.length();l++) {
            for(int i=0;i+l-1<s.length();i++) {
                if(s[i]==s[i+l-1] && memo[i+1][i+l-2]) {
                    memo[i][i+l-1] = true;
                    idx[0] = i, idx[1] = i+l-1;
                }
            }
        }
        
        return s.substr(idx[0],idx[1]-idx[0]+1);
    }
};
