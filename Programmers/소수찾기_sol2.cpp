// "에라스토테네스의 체"로 소수를 미리 구하는 방법. 실행시간 매우 느리고 메모리 사용량 터무니없이 큼.

#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<int,bool>    memo;
unordered_map<int,bool>    is_prime;

void eratos(string numbers) {
    sort(numbers.begin(),numbers.end(),greater<int>());
    for(int i=2;i<=stoi(numbers);i++) {
        is_prime[i] = true;
    }
    for(int i=2;i<=sqrt(stoi(numbers));i++) {
        if(!is_prime[i])    continue;
        
        for(int j=2;i*j<=stoi(numbers);j++) {
            is_prime[i*j] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    eratos(numbers);
    sort(numbers.begin(),numbers.end());
    for(int i=1;i<(1<<numbers.size());i++) {
        string selected;
        for(int j=0;j<numbers.size();j++) {
            if(i&(1<<j)) {
                selected = numbers[numbers.size()-1-j]+selected;
            }
        }
        
        do {
            if(is_prime[stoi(selected)] && !memo[stoi(selected)]) {
                memo[stoi(selected)] = true;
                answer++;
            }
        } while(next_permutation(selected.begin(),selected.end()));
    }
    return answer;
}
