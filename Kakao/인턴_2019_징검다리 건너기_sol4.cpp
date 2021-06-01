// "Union-Find", Time Complexity: O(nlgn), Space Complexity: O(n). (n: stones.size)
// stones 값만 정렬하여 사용하는 경우, stones를 0으로 만들기 위해 Time Complexity O(n^2)가 요구됨. 만약, 값과 위치정보의 쌍 (stones[i],i)을 이용한다면 Time Complexity O(n)으로 가능함.
// stones을 0으로 만들면서 이미 0이 되었던 양옆과 Union을 반복. Union을 반복해주면서 만약 Union된 포리스트의 원소의 갯수가 k이상이 된다면, 이는 연속된 0이 k개 이상이라는 말과 동치이므로 이때의 값이 정답.
// 1) 정렬(O(nlgn)) 2) Union-find를 n회 반복(O(nlg*n)) 이므로 전체 Time Complexity는 O(nlgn).

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int parent[200000];
int sz[200000];
int height[200000];

int find(int node) {
    if(parent[node]==node)  return node;
    return parent[node] = find(parent[node]);
}

void union_height(int node1, int node2) {
    int root1 = find(node1);
    int root2 = find(node2);
    if(root1==root2)    return;
    
    if(height[root1]<height[root2]) {
        parent[root1] = root2;
        sz[root2] += sz[root1];
    }
    else {
        parent[root2] = root1;
        sz[root1] += sz[root2];
    }
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    vector<pair<int,int>>   sorted;
    vector<bool> is_zero(stones.size(),false);
    for(int i=0;i<200000;i++)   {
        parent[i] = i;
        sz[i] = 1;
    }
    
    for(int i=0;i<stones.size();i++) {
        sorted.push_back({stones[i],i});
    }
    sort(sorted.begin(),sorted.end());
    
    for(int i=0;i<sorted.size();i++) {
        is_zero[sorted[i].second] = true;
        
        if(sorted[i].second-1>=0 && is_zero[sorted[i].second-1]) {
            union_height(sorted[i].second-1, sorted[i].second);
        }
        if(sorted[i].second+1<stones.size() && is_zero[sorted[i].second+1]) {
            union_height(sorted[i].second, sorted[i].second+1);
        }
        
        if(sz[find(sorted[i].second)]>=k) {
            answer = sorted[i].first;
            break;
        }
    }
    
    return answer;
}
