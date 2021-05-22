// 출제의도: "조합(비트마스크), 순열, 소수", Time Complexity: O(2^n * n!), Space Complexity: O(2^n * n!).
// 카카오 "후보키"와 동일한 원리(비트마스크)

#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<int,bool>    memo;

bool is_prime(int num) {
    if(num<2)  return false;
    
    for(int i=2;i<=sqrt(num);i++) {
        if(num%i==0)    return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(),numbers.end());
    for(int i=1;i<(1<<numbers.size());i++) {
        string selected;
        for(int j=0;j<numbers.size();j++) {
            if(i&(1<<j)) {
                selected = numbers[numbers.size()-1-j]+selected;
            }
        }
        
        do {
            if(is_prime(stoi(selected)) && !memo[stoi(selected)]) {
                memo[stoi(selected)] = true;
                answer++;
            }
        } while(next_permutation(selected.begin(),selected.end()));
    }
    return answer;
}
