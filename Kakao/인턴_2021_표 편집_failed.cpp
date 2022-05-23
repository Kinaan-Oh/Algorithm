// List/Stack
// STL List 활용하였으나 알 수 없는 오류. 풀이 로직에 문제없으나, stack 대신 동일 기능 vector,deque,list로 변경시 정답의 갯수가 변경되는 이상한 오류.
// 해당 오류는 서버측 문제로 판단됨.

#include <string>
#include <vector>
#include <list>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmdList) {
    string answer(n, 'X');
    list<int> table;
    stack<pair<list<int>::iterator, int>>  stack;
    
    for(int i=0;i<n;i++)    table.push_back(i);
    
    auto p = table.begin();
    advance(p,k);
        
    for(auto cmd: cmdList) {
        if(cmd[0]=='U') {
            int x = stoi(cmd.substr(2));
            advance(p,-x);
        } else if(cmd[0]=='D') {
            int x = stoi(cmd.substr(2));
            advance(p,x);
        } else if(cmd[0]=='C') {
            int v = *p;
            p = table.erase(p);
            stack.push({p,v});
            if(p==table.end())  advance(p,-1);
        } else if(cmd[0]=='Z') {
            table.insert(stack.top().first, stack.top().second);
            stack.pop();
        }
    }
    
    for(auto row: table) {
        answer[row] = 'O';
    }
    return answer;
}
