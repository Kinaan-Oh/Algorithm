// Math(GCD), Time Complexity: O(lgL), Space Complexity: O(1) (L: max of str1.length and str2)
// 논리: 1) If Common Divisor exists -> str1+str2 = str2+str1 <- (x+..+x) + (x+....x) = (x+....x) + (x+..+x)
//      2) candidates = Common Factor of s1 and s2
//      3) Greatest Comomn Divisior = GCD of str1.size and str2.size
//      4) By Euclidean Methods, the Time Complexity of gcd is O(lgL)

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return str1+str2 == str2+str1 ? 
            str1.substr(0, gcd(str1.size(), str2.size())) : "";
    }
};
