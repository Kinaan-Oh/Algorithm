// "Recursive", Time Complexity: O(n), Space Complexity: O(n) (n: s.length)

class Solution {
private:
    string p;
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.length();i++) {
            if(isalpha(s[i])||isdigit(s[i])) {
                p += tolower(s[i]);
            }
        }
        return check(0,p.length()-1);
    }
    
    bool check(int s, int e) {
        if(s>=e)    return true;
        
        if(p[s]==p[e] && check(s+1,e-1))    return true;
        return false;
    }
};
