// 출제의도: "그래프 순회, 순위 개념 이해", Time Complexity: O(n^2+m), Space Complexity: O(n^2) (n: num_of_player, m: results.size)
// 문제 핵심: 자신을 제외한 모든 노드(선수)와 relation(승패 관계)이 있어야 자신의 순위를 결정지을 수 있음.
// 내 풀이의 경우, 승자를 추적하기 위해 역인접리스트를 1개 더 유지하여 2개의 인접리스트를 순회(승자/패자 추적)하는 형태로 수정 가능하나, Time Complexity는 O(n^2+m)으로 동일.
// 이외에 효율성은 떨어지나, 다양한 풀이 방법이 가능(플로이드 워셜: O(n^3+m), Set: O(n^3lgn+m)).

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> adjList[101];   // idx: 1~100
bool relation[101][101];    // idx: 1~100
bool visited[101];  // idx: 1~100

void dfs(int start_node, int cur_node) {
    for(int i=0;i<adjList[cur_node].size();i++) {
        int next_node = adjList[cur_node][i];
        if(visited[next_node])   continue;
        
        relation[start_node][next_node] = true;
        visited[next_node]=true;
        dfs(start_node,next_node);
    }
}

bool determine_ranking(int n, int player) {
    int num_of_relation=0;
    for(int i=1;i<=n;i++) {
        if(relation[player][i]) num_of_relation++;
        if(relation[i][player]) num_of_relation++;
    }
    return (num_of_relation==n-1);
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i=0;i<results.size();i++) {
        adjList[results[i][0]].push_back(results[i][1]);
    }
    for(int i=1;i<=n;i++) {
        fill(visited,visited+101,false);
        visited[i]=true;
        dfs(i,i);
    }
    for(int i=1;i<=n;i++) {
        if(determine_ranking(n,i)) {
            answer++;
        }
    }
    return answer;
}
