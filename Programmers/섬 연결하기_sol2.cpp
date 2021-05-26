// 출제의도: "minimum spanning tree(prim), greedy", Time Complexity: O((V+E)lgV), Space Complexity: O(n^2). (E: costs.size)
// 우선순위 큐 자료구조를 이용한 prim 알고리즘.
// 간선(edge)이 많은 dense graph의 경우, 프림 알고리즘이 크루스칼 알고리즘보다 효율적. 반면, 희소 그래프(sparse graph)이 경우 크루스칼이 효율적.
// 그러나 일반적으로 간선(edge)는 정점보다 훨씬 많으므로 프림 알고리즘을 사용하는 것이 일반적으로 낫다.(구현 측면에서 다익스트라와 유사하므로, 전략적으로 낫다고 판단이 된다.)

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

typedef pair<int,int>   Edge;   // (cost,neighbor_node)

unordered_map<int,vector<Edge>> adjList;
priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
bool visited[100];

void push_adj_edge_of(int node) {
    for(int i=0;i<adjList[node].size();i++) {
        if(!visited[adjList[node][i].second])    pq.push(adjList[node][i]);
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0;i<costs.size();i++) {
        adjList[costs[i][0]].push_back(Edge(costs[i][2],costs[i][1]));
        adjList[costs[i][1]].push_back(Edge(costs[i][2],costs[i][0]));
    }
    
    visited[0] = true;
    push_adj_edge_of(0);
    
    while(!pq.empty()) {
        Edge min_edge = pq.top();
        pq.pop();
        if(visited[min_edge.second])    continue;
        
        visited[min_edge.second] = true;
        answer += min_edge.first;
        push_adj_edge_of(min_edge.second);
    }
    
    return answer;
}
