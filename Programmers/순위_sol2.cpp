// 역인접리스트를 이용한 양방향(승자/패자) 탐색. Time Complexity: O(n^2+m), Space Complexity: O(m+n).

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> adjList[101];
vector<int> inverse_adjList[101];
bool visited[101];

void dfs(vector<int> *adjList,int &num_of_relation, int cur_node) {
    for(int i=0;i<adjList[cur_node].size();i++) {
        int next_node = adjList[cur_node][i];
        if(visited[next_node])   continue;
        
        visited[next_node]=true;
        num_of_relation++;
        dfs(adjList,num_of_relation,next_node);
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i=0;i<results.size();i++) {
        adjList[results[i][0]].push_back(results[i][1]);
        inverse_adjList[results[i][1]].push_back(results[i][0]);
    }
    for(int i=1;i<=n;i++) {
        int num_of_relation=0;
        fill(visited,visited+101,false);
        dfs(adjList,num_of_relation,i);
        dfs(inverse_adjList,num_of_relation,i);
        answer = num_of_relation==n-1 ? answer+1 : answer;
    }
    
    return answer;
}
