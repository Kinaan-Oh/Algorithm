// "Reculsive, Memoization", Time Complexity: O(n^3), Space Compexity: O(n).
// #139. Word Break_failed의 match 중복호출 문제를 memoization으로 최적화. 따라서, s의 각 지점에 대해 match는 최대 1번만 호출.
// 각 match 호출은 1+2+..+s.length-start 의 연산을 진행.(substr은 O(substrig.length)이 걸림) 따라서, 전체 Time Complexity: O(n^3).

class Solution {
private:
    unordered_set<string>  hash_set;
    bool memo[300];
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans=false;
        fill(memo,memo+300,false);
        for(int i=0;i<wordDict.size();i++)  hash_set.insert(wordDict[i]);
        match(ans,s,0);
        return ans;
    }
    
    void match(bool &ans,string &s,int start) {
        if(start==s.length())   ans = true;
        if(memo[start])  return;
        
        for(int i=start;i<s.length();i++) {
            if(hash_set.find(s.substr(start,i-start+1))!=hash_set.end()) {
                memo[start] = true;
                match(ans,s,i+1);
            }
        }
    }
};
