// Brute-Force, Time Complexity: O(L), Space Complexity: O(1) (L: sum of length of str)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        
        for(int i=0;i<strs.size();i++) {
            if(i==0) {
                prefix = strs[0];
            } else {
                string s = commonPrefix(prefix, strs[i]);
                
                if(s.size()<prefix.size())  prefix = s;
            }
        }
        return prefix;
    }
    
    string commonPrefix(string s, string t) {
        int idx = 0;
        
        while(s[idx]==t[idx] && idx<s.size() && idx<t.size()) {
            idx += 1;
        }
        return s.substr(0,idx);
    }
};
