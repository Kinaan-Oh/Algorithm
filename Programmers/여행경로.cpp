// 출제의도: "dfs".
// 티켓의 갯수(간선 개수)에 대한 제한조건이 나와있지 않아, 티켓을 전부 탐색하지 않고 인접 리스트를 선택. 그러나, 티켓을 전부 탐색하는 풀이 역시 통과.

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct Path {
    string city;
    bool used;
    Path(string c):city(c),used(false){}
};

unordered_map<string,vector<Path>> adjList;
vector<string> route;
vector<string> answer;
int num_of_tickets;

void dfs(string city_currently_visiting, int num_of_move) {
    if(num_of_move==num_of_tickets) {
        if(!answer.empty()) answer = route<answer ? route : answer;
        else answer = route;
        return;
    }
    
    for(int i=0;i<adjList[city_currently_visiting].size();i++) {
        if(adjList[city_currently_visiting][i].used)    continue;
    
        string city_to_visit = adjList[city_currently_visiting][i].city;
        adjList[city_currently_visiting][i].used = true;
        route.push_back(city_to_visit);
        dfs(city_to_visit, num_of_move+1);
                    
        route.pop_back();
        adjList[city_currently_visiting][i].used = false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    num_of_tickets = tickets.size();
    for(int i=0;i<tickets.size();i++) {
        adjList[tickets[i][0]].push_back(Path(tickets[i][1]));
    }
    route.push_back("ICN");
    dfs("ICN",0);
    return answer;
}
