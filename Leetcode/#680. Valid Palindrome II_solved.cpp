// Two-Pointer, Time Complexity: O(l), Space Complexity: O(1) (l: s.length)
// deleting at most one 조건을 이용하는 것이 관건. Two-Pointer로 접근하여 최초로 양 끝 문자가 다른 경우 둘 중 하나를 delete(2가지 case) 하여 다시 Palindrome 여부를 판단한다.
// 해당 조건을 이용하는 발상은 생각보다 잘 되지 않았고, 풀이를 진행하는 과정에서 Two-Pointer 관련 좋은 테크닉을 습득할 수 있었다.

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;
        
        while(left<right) {
            if(s[left] == s[right]) {
                left += 1;
                right -= 1;
            } else {
                return isPalindrome(s, left, right-1) || isPalindrome(s, left+1, right);
            }
        }
        return true;
    }
    
    bool isPalindrome(string s, int left, int right) {
        while(left<right) {
            if(s[left] != s[right])    return false;
            left += 1;
            right -= 1;
        }
        return true;
    }
};
