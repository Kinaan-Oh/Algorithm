// 출제의도: "Greedy, Priority Queue", Time Complexity: O((m+n)lgm), Space Complexity: O(m). (m: works.size)
// works에서 1개를 선택하여 1만큼 감소시킬때, works에서 가장 큰 값을 선택하는 것이 야근 피로도를 가장 많이 줄이 수 있다.(Greedy) 이를 n번 반복하면 야근 피로도의 최소값을 구할 수 있다.
// Brute Force하게 works의 최댓값을 찾는다면 Time Complexity: O(mn)으로 비효율적. 따라서, 자료구조 우선순위 큐를 이용하면 works의 최댓값 탐색을 O(m)에서 O(lgm)을 향상시킬 수 있음.
// 우선순위 큐에 m개 원소 삽입, n개 원소 삽입/삭제, m개 원소 삭제가 발생하므로 전체 Time Complexity: O((m+n)lgm)이 된다.

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
