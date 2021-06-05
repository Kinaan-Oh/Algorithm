// "String, Brute Force", Time Complexity: O(n^3), Space Complexity: O(1). (n: s.length)
// string.substr(s)은 O(s.length)만큼 걸린다. 따라서, 문자열 문제를 풀때 substr(), += 와 같은 연산자의 사용을 자제하자.(+=도 O(s.length))

#include <iostream>
#include <string>

using namespace std;

int solution(string s)
{
    int answer=1;
    int sz = s.size();
    for(int i=sz;i>1;i--) {
        for(int j=0;j+i-1<sz;j++) {
            int left = j, right=j+i-1;
            bool is_palindrome=true;
            while(left<right) {
                if(s[left]!=s[right]) {
                    is_palindrome=false;
                    break;
                }
                left++, right--;
            }
            if(is_palindrome)   return max(answer,i);
        }
    }
    return answer;
}
