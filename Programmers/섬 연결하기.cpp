// 출제의도: "minimum spanning tree, greedy", Time Complexity: O(ElgE), Space Complexity: O(n). (E: costs.size)
// Union by Height, Path Compression(find)으로 최적화. 정렬(ElgE)이 병목. 이후 반복문(union-find)은 Elg*n(E:costs.size, lg*: 로그 스타)

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int parent[100];    // idx: 0~99
int height[100];

int find(int node) {
    if(parent[node]==node)  return node;
    return parent[node] = find(parent[node]);
}

bool compare(vector<int> edge1, vector<int> edge2) {
    return edge1[2]<edge2[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int num_of_edge=0;
    for(int i=0;i<100;i++)  parent[i]=i;
  
    sort(costs.begin(),costs.end(),compare);
    
    for(int i=0;i<costs.size() && num_of_edge<n;i++) {
        int root1 = find(costs[i][0]);
        int root2 = find(costs[i][1]);
        
        if(root1 != root2) {
            
            if(height[root1]<height[root2])     parent[root1] = root2;
            else if(height[root1]>height[root2])    parent[root2] = root1;
            else {
                parent[root1] = root2;
                height[root2]++;
            }
            answer += costs[i][2];
            num_of_edge++;
        }
    }
    return answer;
}
