// 1차시도 : Stack 2개를 이용하여 시도. 극한의 코드 복잡성과 수많은 예외케이스 처리로 90%의 테스트 케이스 정도만 통과 후 해당 방법 폐기.
// 2차시도 : 일반적으로 stack을 이용한 풀이는 Recursion으로 변환가능. Recursion을 이용하여 시도하였지만, 마찬가지로 너무 많은 예외케이스 처리로 실패 중. 익일 재시도.

// 출제의도: Implement/Recursion or Stack, Time Complexity: O(l), Space Complexity: O(l). (l: s.length)
// [,] hierarchy가 쌓일 때마다 Recursive하게 decode. idx를 reference type으로 정의한 이유는 각 Recursion의 return후 update된 idx를 사용해야 하기 때문.
// 결론적으로 s 를 1회 순회하여 decode를 완료하게 된다. space는 call stack(maximum l/2회)를 사용한다.
// 생각보다 구현난이도가 있는 문제...

class Solution {
public:
    string decodeString(string s) {
        int idx= 0;
        return decodeString(s, idx);
    }
    
    string decodeString(string &s, int &idx) {
        string result;
        string num;
        
        for(;idx<s.length();idx++) {
            if(s[idx]=='[') {
                string next = decodeString(s, ++idx);
                
                for(int i=0;i<stoi(num);i++) {
                    result += next;
                }
                num.clear();
            } else if(s[idx]==']') {
                break;
            } else if(isdigit(s[idx])) {
                num += s[idx];
            } else if(isalpha(s[idx])) {
                result += s[idx];
            }
        }
        return result;
    }
};
