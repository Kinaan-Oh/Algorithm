// 출제의도: "BFS, 구현(회전 변환)". 
// convert_pos_hashable(vector<Pos> pos)모듈 구현시 각 좌표별로 구분자가 꼭 필요함. 예를들어, 1,10,0,0 과 11,0,0,0을 구분하기 위해서 구분자가 필요. 이 부분을 고려하지 못하여, 2시간동안 디버깅.

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

typedef pair<int,int>   Pos;

struct Agent {
    vector<Pos> pos;
    int time;
    Agent(vector<Pos> p, int t) {
        pos = p;
        sort(pos.begin(),pos.end());
        time = t;
    }
};

unordered_map<string,bool> visited;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

string convert_pos_hashable(vector<Pos> pos) {
        return to_string(pos[0].first)+","+to_string(pos[0].second)+","+to_string(pos[1].first)+","+to_string(pos[1].second);
}

Pos rotate_90_clockwise(Pos axis, Pos target) {
    Pos relative_pos_of_target_to_axis = Pos(target.first-axis.first,target.second-axis.second);
    return Pos(axis.first+relative_pos_of_target_to_axis.second, axis.second-relative_pos_of_target_to_axis.first);
}

Pos rotate_90_counter_clockwise(Pos axis, Pos target) {
    Pos relative_pos_of_target_to_axis = Pos(target.first-axis.first,target.second-axis.second);
    return Pos(axis.first-relative_pos_of_target_to_axis.second, axis.second+relative_pos_of_target_to_axis.first);
}

bool isOutOfBound(vector<vector<int>> &board, Pos pos) {
    int N = board.size();
    if(pos.first<0 || pos.first>=N || pos.second<0 || pos.second>=N)    return true;
    return false;
}

int bfs(vector<vector<int>> &board) {
    Pos destination = Pos(board.size()-1,board.size()-1);
    Agent agent_init = Agent({Pos(0,0),Pos(0,1)},0);
    queue<Agent>    que;
    visited[convert_pos_hashable(agent_init.pos)] = true;
    que.push(agent_init);
    
    while(!que.empty()) {
        Agent agent_cur = que.front();
        que.pop();

        if(agent_cur.pos[0]==destination || agent_cur.pos[1]==destination)  return agent_cur.time;
        
        for(int i=0;i<4;i++) {
            vector<Pos> next = {Pos(agent_cur.pos[0].first+dx[i],agent_cur.pos[0].second+dy[i]),Pos(agent_cur.pos[1].first+dx[i],agent_cur.pos[1].second+dy[i])};
            if(isOutOfBound(board,next[0]) || isOutOfBound(board,next[1]) || visited[convert_pos_hashable(next)] || board[next[0].first][next[0].second]==1 || board[next[1].first][next[1].second]==1)    continue;
            
            visited[convert_pos_hashable(next)]=true;
            que.push(Agent(next,agent_cur.time+1));
        }
        
        for(int i=0;i<2;i++) {
            vector<Pos> next;
            Pos axis = agent_cur.pos[i];
            Pos target = agent_cur.pos[(i+1)%2];
            
            Pos target_rotated_90_clockwise = rotate_90_clockwise(axis,target);
            next = {axis,target_rotated_90_clockwise};
            sort(next.begin(),next.end());
            Pos check_obstacle = rotate_90_counter_clockwise(target,axis);
            if(!isOutOfBound(board,target_rotated_90_clockwise) && board[target_rotated_90_clockwise.first][target_rotated_90_clockwise.second]==0 && !visited[convert_pos_hashable(next)] && board[check_obstacle.first][check_obstacle.second]==0) {
                visited[convert_pos_hashable(next)]=true;
                que.push(Agent(next,agent_cur.time+1));
            }
            
            Pos target_rotated_90_counter_clockwise = rotate_90_counter_clockwise(axis,target);
            next = {axis,target_rotated_90_counter_clockwise};
            sort(next.begin(),next.end());
            check_obstacle = rotate_90_clockwise(target,axis);
            if(!isOutOfBound(board,target_rotated_90_counter_clockwise) && board[target_rotated_90_counter_clockwise.first][target_rotated_90_counter_clockwise.second]==0 && !visited[convert_pos_hashable(next)] && board[check_obstacle.first][check_obstacle.second]==0) {
                visited[convert_pos_hashable(next)]=true;
                que.push(Agent(next,agent_cur.time+1));
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    answer = bfs(board);
    return answer;
}
