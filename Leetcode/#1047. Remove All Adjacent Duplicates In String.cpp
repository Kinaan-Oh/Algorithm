// Stack, Time Complexity: O(l), Space Complexity: O(l) (l: s.length)

class Solution {
public:
    string removeDuplicates(string s) {
        string  stack;
        
        for(auto c: s) {
            if(stack.empty() || stack.back()!=c) {
                stack.push_back(c);
                continue;
            } else {
                stack.pop_back();
            }
        }
        return stack;
    }
};
