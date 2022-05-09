// Math/Data Type/String
// convert 길이가 큰 경우(radix: 3) Int Type 사용시 core dumped error. Int Type 대신 Long Long Type으로 변경 필요.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string convert(int n, int k) {
    string result;
    
    while(n) {
        result = to_string(n%k) + result;
        n /= k;
    }
    return result;
}

bool isPrime(long long n) {
    if(n<2) return false;
    
    for(long long i=2;i*i<=n;i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string candidate;
    string converted = convert(n, k);
    
    for(auto c: converted) {
        if(c=='0') {
            if(!candidate.empty() && isPrime(stoll(candidate))) {
                answer += 1;
            }
            candidate.clear();
        } else {
            candidate += c;
        }
    }
    if(converted.back()!='0' && isPrime(stoll(candidate))) {
        answer += 1;
    }
    return answer;
}
