// "구현", Time Complexity: O(n), Space Complexity: O(n)
// Palindrome 정의: 회문(回文) 또는 팰린드롬(palindrome)은 거꾸로 읽어도 제대로 읽는 것과 같은 문장이나 낱말, 숫자, 문자열(sequence of characters).
// sol1은 Palindrome을 재귀적으로 정의하여 풀이했다면(팰린드롬은 양끝 문자열이 같고, 양끝을 제외하 문자열이 역시 팰린드롬이다.), 이 풀이는 정의(뒤집은 것과 원래의 것이 같은)에 따르 풀이.
// 아래 주석 표시된 코드는 Time Limit Exceeded이 발생했는데, 이는 string의 += 연산자의 Time Complexity 때문이다. C++ 레퍼런스에는 string의 += 연산자의 Time Complexity가 "Unspecified"
// 되어있고 대략적으로 새로 생생되는 문자열의 길이에 비례한다고 나와있는데, 이 문제를 통해 Time Complexity는 새로 생성되는 문자열의 길이 보다는 더해지는 문자열의 길이에 비례함을 알 수 있었다.
// 주석처리되 코드의 cur + reversed_s 부분은 길이 1인 문자열에 긴 문자열을 더하게 되므로 거의 항상 resize될 것이다(O(n)). 반면, filtered_s += tolower(s[i])의 경우 긴 문자열에 길이 1인 문자열을 
// 더하는 상황으로 resize가 항상 되지는 않을 것이다.(개인적으로 생각하기로 amortized O(1))
// 정리하면, 긴 문자열에 길이 1이 문자열을 += 연산은 O(1)으로 간주해도 좋고, 반대로 길이 1인 문자열에 긴 문자열을 += 연산은 O(n)(n: 연접된 문자열의 길이)라고 봐야한다.

class Solution {
private:
    string filtered_s, reversed_s;
    
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.length();i++) {
            if(isalnum(s[i])) {
                filtered_s += tolower(s[i]);
            }
        }
        reversed_s = filtered_s;
        reverse(reversed_s.begin(),reversed_s.end());
        return filtered_s == reversed_s;
    }
};



// class Solution {
// private:
//     string filtered_s, reversed_s;
    
// public:
//     bool isPalindrome(string s) {
//         for(int i=0;i<s.length();i++) {
//             if(isalnum(s[i])) {
//                 string cur(1,tolower(s[i]));
//                 filtered_s += cur;
//                 reversed_s = cur + reversed_s;
//             }
//         }
//         return filtered_s == reversed_s;
//     }
// };
