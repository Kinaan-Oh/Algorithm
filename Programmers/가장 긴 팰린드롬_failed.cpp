// "Brute Force", Time Complexity: O(n^3), Space Complexity: O(1). (n: s.length)
// 

#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string s) {
    int left=0, right=s.size()-1;
    while(left<right) {
        if(s[left]!=s[right])   return false;
        left++, right--;
    }
    return true;
}

int solution(string s)
{
    int answer=0;
    for(int i=0;i<s.size();i++) {
        for(int j=1;j<=s.size()-i;j++) {
            if(is_palindrome(s.substr(i,j))) {
                answer = max(answer,j);
            }
        }
    }
    return answer;
}
