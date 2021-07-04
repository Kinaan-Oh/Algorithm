// 출제의도: "Sliding Window", Time Complexity: O(n), Space Complexity: O(n) (n: s.length)
// window는 항상 중복없는 문자열을 포항하면서 이동.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        unordered_set<char> hash_set;
        int left=0, right=0;    // [left,right)
        int num = 0;
        while(right<s.length()) {
            if(hash_set.find(s[right])==hash_set.end()) {
                hash_set.insert(s[right++]);
                num++;
                answer = max(answer, num);
                continue;
            }
            
            while(s[left]!=s[right]) {
                hash_set.erase(s[left++]);
                num--;
            }
            hash_set.erase(s[left++]);
            num--;
        }
        return answer;
    }
};
