// 출제의도: "구현(모듈화)"

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
int column[101][101];
int beam[101][101];

bool obey_rule_of_column(vector<int> pos) {
    if(pos[1]==0)   return true;
    if(beam[pos[0]][pos[1]]==1 || beam[pos[0]-1][pos[1]]==1)    return true;
    if(column[pos[0]][pos[1]-1]==1) return true;
    return false;
}

bool obey_rule_of_beam(vector<int> pos) {
    if(column[pos[0]][pos[1]-1]==1 || column[pos[0]+1][pos[1]-1]==1)    return true;
    if(beam[pos[0]-1][pos[1]]==1 && beam[pos[0]+1][pos[1]]==1)  return true;
    return false;
}

void establish_column(vector<int> pos) {
    if(obey_rule_of_column(pos))    column[pos[0]][pos[1]] = 1;
}

void establish_beam(vector<int> pos) {
    if(obey_rule_of_beam(pos))  beam[pos[0]][pos[1]] = 1;
}

bool is_possible_to_remove(void) {
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++) {
            if(column[i][j]==1 && !obey_rule_of_column({i,j}))    return false;
            if(beam[i][j]==1 && !obey_rule_of_beam({i,j}))  return false;
        }
    }
    return true;
}

void remove_column(vector<int> pos) {
    column[pos[0]][pos[1]] = 0;
    if(!is_possible_to_remove())    column[pos[0]][pos[1]] = 1;
}

void remove_beam(vector<int> pos) {
    beam[pos[0]][pos[1]] = 0;
    if(!is_possible_to_remove())    beam[pos[0]][pos[1]] = 1;
}

void perform_column(vector<int> command) {
    switch(command[2]) {
        case 0: // remove
            remove_column({command[0],command[1]});
            break;
        case 1: // establish
            establish_column({command[0],command[1]});
            break;
    }
}

void perform_beam(vector<int> command) {
    switch(command[2]) {
        case 0: // remove
            remove_beam({command[0],command[1]});
            break;
        case 1: // establish
            establish_beam({command[0],command[1]});
            break;
    }
}

void perform(vector<int> command) {
    switch(command[2]) {
        case 0: // 기둥
            perform_column({command[0],command[1],command[3]});
            break;
        case 1: // 보
            perform_beam({command[0],command[1],command[3]});
            break;
    }
}

bool compare(vector<int> &frame1, vector<int> &frame2) {
    if(frame1[0]==frame2[0]) {
        if(frame1[1]==frame2[1])    return frame1[2]<frame2[2];
        return frame1[1]<frame2[1];
    }
    return frame1[0]<frame2[0];
}

void set_answer(vector<vector<int>> &answer) {
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++) {
            if(column[i][j]==1) answer.push_back({i,j,0});
            if(beam[i][j]==1)   answer.push_back({i,j,1});
        }
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    for(int i=0;i<build_frame.size();i++) {
        perform(build_frame[i]);
    }
    set_answer(answer);
    sort(answer.begin(),answer.end(),compare);
    return answer;
}
