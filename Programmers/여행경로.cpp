// 출제의도: "dfs"

#include <string>
#include <vector>
#include <queue>
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
