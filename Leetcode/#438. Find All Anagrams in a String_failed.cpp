// Brute-Force, Time Complexity: O(sp), Space Complexity: O(p) (s: s.length, p: p.length)
// Time Limit Exceeded, 33 / 61 test cases passed.

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> answer;
        
        for(int i=0;i<s.length();i++) {
            unordered_multiset<char>    set;
            
            for(auto c: p)  set.insert(c);
            for(int j=i;j<i+p.length();j++) {
                if(j>=s.length())   break;
                if(set.find(s[j]) != set.end())    set.erase(set.find(s[j]));;
            }
            if(set.empty()) answer.push_back(i);
        }
        return answer;
    }
};
