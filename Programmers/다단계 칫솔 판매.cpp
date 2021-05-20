// 출제의도: "트리(parent배열 표현), 해시테이블", Time Complexity: O(seller.size()*h), Space Complexity: O(n). (n: enroll.size, h:노드 깊이)

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string,string>    parent;
unordered_map<string,int>   sales_profit;

void distribute_profit(string name, int sales) {
    if(sales==0)    return;
    int profit_distribution = sales/10;
    sales_profit[name] += (sales-profit_distribution);
    distribute_profit(parent[name], profit_distribution);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for(int i=0;i<enroll.size();i++) {
        parent[enroll[i]] = referral[i];
    }
    for(int i=0;i<seller.size();i++) {
        distribute_profit(seller[i], amount[i]*100);
    }
    for(int i=0;i<enroll.size();i++) {
        answer.push_back(sales_profit[enroll[i]]);
    }
    return answer;
}
