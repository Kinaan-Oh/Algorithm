// "에라스토테네스의 체"로 소수를 미리 구하는 방법. Time Complexity: O(2^n * n! + 10^n * lgn), Space Complexity: O(2^n * n! + 10^n).
// 입력 n이 7이하로 매우 작으므로, 해당 범위에서 에라토스테네스의 체가 병목. n이 매우 커진다면, sol1 보다 좋은 코드가 될 수 있을 것이지만, n이 작다면 좋지 않음.

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
