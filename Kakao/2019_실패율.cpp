// Prefix sum, Sort. Time Complexity: O(NlgN), Space Complexity: O(N).

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int numOfPlayersHaveNotCleared[502];    // idx: 1~501
int numOfPlayersArrived[502];   //idx: 1~501

double getFailRate(int stage) {
    if(numOfPlayersArrived[stage]==0)  return 0;
    return (double)numOfPlayersHaveNotCleared[stage]/numOfPlayersArrived[stage];
}

bool compare(int stage1, int stage2) {
    if(getFailRate(stage1)==getFailRate(stage2))    return stage1<stage2;
    return getFailRate(stage1)>getFailRate(stage2);
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    for(int i=0;i<stages.size();i++) {
        numOfPlayersHaveNotCleared[stages[i]]++;
        numOfPlayersArrived[stages[i]]++;
    }
    for(int i=N+1;i>1;i--) {
        numOfPlayersArrived[i-1] += numOfPlayersArrived[i];
    }
    for(int i=1;i<=N;i++) answer.push_back(i);
    sort(answer.begin(),answer.end(),compare);
    return answer;
}ㅍ
