// 출제의도: "최단경로: BFS". Time Complexity: O(n), Space Complexity: O(n).

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> adjList[20001]; // idx: 1~20000
bool visited[20001];

struct State {
    int node;
    int dist;
    State(int n, int d):node(n),dist(d){}
};

int bfs(void) {
    int dist=-1;
    int numOfNodes=0;
    queue<State> que;
    visited[1]=true;
    que.push(State(1,0));
    while(!que.empty()) {
        State cur = que.front();
        que.pop();
        if(cur.dist>dist) {
            dist = cur.dist;
            numOfNodes=1;
        }
        else    numOfNodes++;
        
        for(int i=0;i<adjList[cur.node].size();i++) {
            int nextNode = adjList[cur.node][i];
            if(visited[nextNode])   continue;
            
            visited[nextNode]=true;
            que.push(State(nextNode,cur.dist+1));
        }
    }
    return numOfNodes;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i=0;i<edge.size();i++) {
        adjList[edge[i][0]].push_back(edge[i][1]);
        adjList[edge[i][1]].push_back(edge[i][0]);
    }
    answer = bfs();
    return answer;
}
