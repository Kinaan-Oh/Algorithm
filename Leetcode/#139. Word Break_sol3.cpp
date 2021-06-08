// "DP", Time Complexity: O(n^3), Space Complexity: O(n). 
// s[0...i]는 s[0...k]가 가능하고 s[k+1...i]가 wordDict에 포함되어있다면 가능하다.
// dp[i]는 s[0...i]의 가능여부를 표현하고, bottom-up으로 i=0 -> i:s.length-1 순으로 푼다.
// 최종해는 dp[s.length-1]에 구해진다.

class Solution {
private: 
    unordered_set<string>   hash_set;
    bool dp[300]; // dp[i]: s[0...i]가 가능한지
    // dp[i] is true, if any k satisfy "dp[k] and s[k+1..i] is in wordDict (k:0~i-1)"
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<wordDict.size();i++)  hash_set.insert(wordDict[i]);
        fill(dp,dp+300,false);
        dp[0] = hash_set.find(s.substr(0,1))!=hash_set.end() ? true : false;
        for(int i=1;i<s.length();i++) {
            for(int j=0;j<i;j++) {
                if(dp[j] && hash_set.find(s.substr(j+1,i-j))!=hash_set.end()) {
                    dp[i] = true;
                    break;
                }
            }
            if(hash_set.find(s.substr(0,i+1))!=hash_set.end())  dp[i] = true;
        }
        return dp[s.length()-1];
    }
};
