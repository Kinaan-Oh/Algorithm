// 출제의도: HashSet or Sort, Time Complexity: O(L), Space Complexity: O(L) (L: s.length + t.length)

class Solution {
private:
    unordered_multiset<char>    set;
    
public:
    bool isAnagram(string s, string t) {
        for(auto c: s)   set.insert(c);
        for(auto c: t) {
            auto pos = set.find(c);
            if(pos == set.end())    return false;
            set.erase(pos);
        }
        return set.empty();
    }
};
