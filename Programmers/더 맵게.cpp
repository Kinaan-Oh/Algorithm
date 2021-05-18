// 출제의도: "힙", Time Complexity: O(n), Space Complexity: O(n).(n: scoville.size)

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<int> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i=0;i<scoville.size();i++) {
        pq.push(-scoville[i]);
    }
    
    while(-pq.top()<K && pq.size()>=2) {
        int least_spicy_food = -pq.top();
        pq.pop();
        int second_least_spicy_food = -pq.top();
        pq.pop();
        pq.push(-(least_spicy_food+second_least_spicy_food*2));
        answer++;
    }
    if(-pq.top()<K) return -1;
    return answer;
}
