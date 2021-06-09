// 출제의도: "Greedy, Priority Queue", Time Complexity: O((m+n)lgm), Space Complexity: O(m). (m: works.size)
// works에서 1개를 선택하여 1만큼 감소시킬때, works에서 가장 큰 값을 선택하는 것이 야근 피로도를 가장 많이 줄이 수 있다.(Greedy) 이를 n번 반복하면 야근 피로도의 최소값을 구할 수 있다.

#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(int i=0;i<works.size();i++)    pq.push(works[i]);
    while(!pq.empty() && n) {
        int cur = pq.top();
        pq.pop();
        if(cur-1>0) pq.push(cur-1);
        n--;
    }
    while(!pq.empty()) {
        answer += pq.top()*pq.top();
        pq.pop();
    }
    return answer;
}
