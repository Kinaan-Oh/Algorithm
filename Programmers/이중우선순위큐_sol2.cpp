// 출제의도: "우선순위 큐", Time Complexity: O(nlgn), Space Complexity: O(n). (n: operations.size)
// multiset 자료구조를 이용하여 간단히 해결 가능. set/multiset은 내부적으로 정렬(ordered)하여 보관(balanced binary search tree이기 때문). 이 속성을 이용하여 최소/최대값을 쉽게 구할 수 있음.

#include <string>
#include <vector>
#include <set>

using namespace std;

multiset<int>   dual_pq;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for(int i=0;i<operations.size();i++) {
        int num = stoi(operations[i].substr(2));
        switch(operations[i][0]) {
            case 'I':
                dual_pq.insert(num);
                break;
            case 'D':
                if(dual_pq.empty()) continue;
                
                if(num==1)  dual_pq.erase(--dual_pq.end());
                else    dual_pq.erase(dual_pq.begin());
                break;
        }
    }
    if(dual_pq.empty()) answer = {0,0};
    else    answer = {*(--dual_pq.end()),*dual_pq.begin()};
    return answer;
}
