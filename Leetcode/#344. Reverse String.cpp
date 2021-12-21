// 출제의도: Two-Pointer, Time Complexity: O(n), Space Complexity: O(1). (n: s.size)
// 다양한 풀이방법이 있겠지만, In-Place한 풀이로 Two-Pointer가 적절. Recursion도 가능하겠지만 Call Stack이 쌓이기 때문에 엄밀하게 따지면 Space Complexity는 O(n).

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0;i<s.size()/2;i++) {
            swap(s[i], s[s.size()-1-i]);
        }
    }
};
