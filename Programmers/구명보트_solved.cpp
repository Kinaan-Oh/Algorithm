// 출제의도: "greedy", Time Complexity: O(n), Space Complexity: O(1). (n: people.size)
// 논리: 가장 무거운 사람을 가능한 2명으로 탑승시키기 위해서는 가장 작은 몸무게인 사람과 탑승시켜야만 한다. 만일, 무게제한이 넘어간다면 혼자 탑승해야만 하고 그렇지않다면 동승시킨다.
// 시간초과로 인해 실패한 이전 논리는 "배를 기준으로 항상 최대 무게를 채운다"였는데, 이는 답(정확성 통과)을 내놓지만(최소한의 배를 사용하기) 과한 접근이었다. 만일, 모든 배의 여유무게를 최소화하라는 문제였다면, 
// 해당 논리는 적합하였겠지만, 이 문제는 그런 문제가 아니다.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end(),greater<int>());
    int left=0, right=people.size()-1;
    while(left<right) {
        if(people[left]+people[right]>limit) {
            left++;
        }
        else {
            left++;
            right--;
        }
        answer++;
    }
    answer = left==right ? answer+1 : answer;
    return answer;
}
