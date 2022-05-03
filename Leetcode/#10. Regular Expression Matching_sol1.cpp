// Recursion

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())   return s.empty();
        
        bool fistMatch = !s.empty() && (s.front() == p.front() || p.front() == '.');
        
        if(p.length()>1 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (fistMatch && isMatch(s.substr(1), p));
        } else {
            return fistMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};
