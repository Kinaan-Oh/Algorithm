// Time Complexity: O(priorities.length^2), Space Complexity: O(priorities.length)

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    unordered_map<int,int>  ht; // priority:cnt
    queue<int> que; // index
    for(int i=0;i<priorities.size();i++) {
        ht[priorities[i]]++;
        que.push(i);
    }
    while(!que.empty()) {
        int cur = que.front();
        int cur_priority = priorities[cur];
        bool print = true;
        que.pop();
        for(int i=cur_priority+1;i<=9;i++) {
            if(ht[i]>0) {
                que.push(cur);
                print=false;
                break;
            }
        }
        
        if(print) {
            ht[cur_priority]--;
            answer++;
            if(cur==location)   break;
        }
    }
    return answer;
}
