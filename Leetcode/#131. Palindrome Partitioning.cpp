// 출제의도: Backtrack/ DP, Time Complexity: O(n*2^n), Space Complexity: O(n^2). (n: s.length)
// 기본적으로 partitioning을 구현할 능력이 있어야함. backtrack 노드 갯수는 2^n 이고 각 노드에서 호출되는 substr()의 worstcase time complexity = O(n) 이므로 time complexity = O(n*2^n).
// Palindrome의 성질을 이용하여 주어진 문자열의 길이가 l 일때 O(l)로 Palindrome 여부를 판단할 수 있지만, 중복호출을 막기위해 한번 판단한 문자열의 Palindrome 여부를 Memoize하여 개선.

class Solution {
private:
    bool dp[16][16];
        
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>  answer;
        vector<string>  cur;
        init();
        partition(answer, cur, s, 0, s.size()-1);
        return answer;
    }
    
    void init() {
        fill(&dp[0][0], &dp[15][15], false);
        for(int i=0;i<15;i++)   dp[i][i] = true;
    }
    
    void partition(vector<vector<string>> &answer, vector<string> &cur, string &s, int begin, int end) {
        if(begin>end) {
            answer.push_back(cur);
            return;
        }
            
        for(int i=begin;i<=end;i++) {
            if(is_palindrome(s, begin, i)) {
                cur.push_back(s.substr(begin,i-begin+1));
                partition(answer, cur, s, i+1, end);
                cur.pop_back();
            }
        }
    }
    
    bool is_palindrome(string &s, int begin, int end) {
        if(dp[begin][end] || begin>=end)  return true;
        
        dp[begin][end] = s[begin]==s[end] && is_palindrome(s, begin+1, end-1);
        return dp[begin][end];
    }
};
