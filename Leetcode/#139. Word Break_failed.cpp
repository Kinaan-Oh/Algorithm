// "Brute Force", Time Complexity: O((n+1)!), Space Complexity: O(m). (n: s.length, m: wordDict.size)
// Time Limit Exceeded

class Solution {
private:
    unordered_map<string,bool>  ht;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans=false;
        for(int i=0;i<wordDict.size();i++)  ht[wordDict[i]]=true;
        match(ans,s,0);
        return ans;
    }
    
    void match(bool &ans,string &s,int start) {
        if(start==s.length()) {
            ans = true;
            return;
        }
        
        for(int i=start;i<s.length();i++) {
            if(ht[s.substr(start,i-start+1)])   match(ans,s,i+1);
        }
    }
};
