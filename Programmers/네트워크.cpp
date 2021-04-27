// Connected Component(DFS). O(n^2): 인접행렬 computers의 각 행을 한번씩만 O(n)으로 순회.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int numOfConnectedComponent;
bool visited[200];  // idx: 0~199

void dfs(vector<vector<int>> &computers, int numOfComputer)
{
    int n = computers.size();
    for(int col=0;col<n;col++)
    {
        if(col==numOfComputer)  continue;
        
        if(computers[numOfComputer][col]==1 && !visited[col]) {
            visited[col] = true;
            dfs(computers,col);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            dfs(computers,i);
            numOfConnectedComponent++;
        }
    }
    answer = numOfConnectedComponent;
    return answer;
}
