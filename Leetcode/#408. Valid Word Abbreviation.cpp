// Two-Pointer, Time Complexity: O(m+n), Space Complexity: O(1) (m: word.size, n:abbr.size)

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int p1 = 0;
        int p2 = 0;
        
        while(p1<word.size() && p2<abbr.size()) {
            if(word[p1]==abbr[p2]) {
                p1 += 1;
                p2 += 1;
                continue;
            }
            
            if(abbr[p2]=='0' || isalpha(abbr[p2]) && word[p1]!=abbr[p2])   return false;
            
            int start = p2;
            while(isdigit(abbr[p2])) {
                p2 += 1;
            }
            p1 += stoi(abbr.substr(start, p2-start));
        }
        return p1==word.size() && p2==abbr.size();
    }
};
