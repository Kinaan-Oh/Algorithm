// 출제의도: "BFS, 구현(회전 변환)". 
// convert_pos_hashable(vector<Pos> pos)모듈 구현시 각 좌표별로 구분자가 꼭 필요함. 예를들어, 1,10,0,0 과 11,0,0,0을 구분하기 위해서 구분자가 필요. 이 부분을 고려하지 못하여, 2시간동안 디버깅.
// -> 독립적인 데이터들을 하나로 묶을 경우, 데이터간 간섭을 막기 위해 구분자가 필요하다는 것을 배움.

// <7/12 리뷰>
// 1) unordered_map을 unordered_set으로 대체하는 것이 보다 나을 것 같다.
// 2) isOutOfBound 네이밍을 is_out_of_bound로 바꾸는 것이 일관적일 것 같다.
// 3) bfs 모듈 코드길이가 세로로 지나치게 길어 가독성이 많이 떨어짐. 모듈화를 통해 보다 간결하게 리팩토링이 필요함.
// 4) vector를 set의 key로 사용하는 것은 어려움.(hash를 직접 구현해야함. 반면 swift는 Hashable을 이용하여 간단하게 사용할 수 있음.) string을 key로 하기위해 vector를 string으로 변환하는 과정에 
// 있어 데이터 사이의 구분자가 필요.

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
