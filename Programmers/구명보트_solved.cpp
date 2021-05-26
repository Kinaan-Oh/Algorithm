// 출제의도: "greedy", Time Complexity: O(n), Space Complexity: O(1). (n: people.size)
// "가장 작은 몸무게인 사람을 동승할 수 있는(limit을 넘지 않는) 가장 큰 몸무게인 사람에게 할당."

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
