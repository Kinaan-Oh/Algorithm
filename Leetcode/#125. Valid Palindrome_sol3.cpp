// "Two Pointer", Time Complexity: O(n), Space Complexity: O(1) (n: s.length)
// 투 포인터를 이용한 Space Complexity O(1) 풀이.

class Solution {

public:
    bool isPalindrome(string s) {
        int left=0, right=s.length()-1;
        while(left<right) {
            while(left<s.length() && !isalnum(s[left]))    left++;
            while(right>=0 && !isalnum(s[right]))   right--;
            if(!(left<right))   break;
            
            if(tolower(s[left])!=tolower(s[right]))    return false;
            left++, right--;
        }
        
        return true;
    }
};
