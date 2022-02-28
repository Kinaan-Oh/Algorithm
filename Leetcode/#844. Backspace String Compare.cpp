// Stack, Time Complexity: O(m+n), Space Complexity: O(1) (m: s.size, n: t.size)
// String의 pop_back/push_back method(둘다 O(1))를 이용하여 Stack처럼 풀이.
// Two-Pointer 학습을 위해 선택했지만, 해당 풀이는 억지스런 풀이이므로 Stack으로 풀이.

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return build(s)==build(t);
    }
    
    string build(string s) {
        string ret;
        
        for(auto c: s) {
            if(c=='#') {
                if(!ret.empty())    ret.pop_back();
            } else {
                ret.push_back(c);
            }
        }
        return ret;
    }
};
