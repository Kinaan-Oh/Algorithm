// "Brute Force", Time Complexity: O(n^2*2^n), Space Complexity: O(m+n). (n: s.length, m: wordDict.size)
// Time Complexity 증명: T(n)을 match의 호출횟수라고 할때, T(n) = T(n-1)+T(n-2)+ ... + T(0) -> T(n) = 2*T(n-1) -> T(n)=2^n.
// 각 호출은 substr(O(substring.length))를 "반복" 호출하므로 O(n^2)으로 근사. 정리하면 각 호출당 O(n^2)의 substr() 연산을 하고, 2^n 호출이 발생하므로 Time Complexity: O(n^2*2^n).
// Time Complexity가 매우 크므로 Time Limit Exceeded.

class Solution {
private:
    unordered_set<string>  hash_set;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans=false;
        for(int i=0;i<wordDict.size();i++)  hash_set.insert(wordDict[i]);
        match(ans,s,0);
        return ans;
    }
    
    void match(bool &ans,string &s,int start) {
        if(start==s.length())   ans = true;
    
        for(int i=start;i<s.length();i++) {
            if(hash_set.find(s.substr(start,i-start+1))!=hash_set.end())   match(ans,s,i+1);
        }
    }
};
