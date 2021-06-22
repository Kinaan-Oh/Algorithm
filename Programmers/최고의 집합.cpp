// 출제의도: "Math, Greedy", Time Complexity: O(n), Space Complexity: O(n).
// idea: "n개의 수 a1, a2, ... ,an 의 합이 s일때, 곱 a1*a2*...*an의 최댓값은 a1 = a2 = ... = an = Avg(a1~an) 일 때다."
// 만약 위의 상황에서 두 수 a1과 a2를 합(a1+a2)이 2*Avg(a1~an)인 다른 두 수로 바꾼다고 하자. 두 수의 차 abs(a1-a2)가 0에서 0보다 커진다.
// a1*a2 = 4*((a1+a2)^2 - (a1-a2)^2) (a1+a2 = 2*Avg(a1~an)) 가 성립하고, 두 수의 편차 (a1-a2)가 커질수록 a1*a2는 커지므로, a1*a2는 원래(a1=a2=Avg(a1~an))보다 커진다.
// 따라서, n개의 수를 최대한 평균값에 가깝도록 해야 곱은 최대가 된다.
// 이를 위해 합 s를 n등분한 몫 Q를 n개의 수로 할당하고, 나머지를 n개의 수에 1씩 분배한다.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s<n)    return {-1};
    
    int quotient = s/n, remainder = s%n;
    for(int i=0;i<n-remainder;i++) {
        answer.push_back(quotient);
    }
    for(int i=0;i<remainder;i++) {
        answer.push_back(quotient+1);
    }
    return answer;
}
