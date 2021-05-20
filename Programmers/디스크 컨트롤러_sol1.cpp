// 출제의도: "우선순위 큐"
// 나의 풀이는 정해는 아니지만(타이머 인터럽트 기반 스케줄러를 변수 clk를 통해 구현한 것이라 비효율일 수밖에 없음), OS강의 수강시 구현했던 프로세스 스케줄러의 개념을 복습겸 구현함.
// OS강의에서 구현했던 스케줄러는 멀티레벨 피드백 큐 방식이라, 여기서 구현한 SPN(Shortest Process Next)의 구현은 비교적 많이 쉬웠음.

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

enum p_state {
    PROC_UNUSED,
    PROC_RUN,
    PROC_ZOMBIE
};

struct Process {
    int pid;
    p_state state;
    int time_to_use;
    Process(int p, p_state s,int t):pid(p),state(s),time_to_use(t){}
};

struct Compare {
    bool operator()(Process &p1, Process &p2) {
        return p1.time_to_use>p2.time_to_use;
    }
};

vector<Process> procs;
unordered_map<int,int>  proc_req;   //[pid:request time]
unordered_map<int,int>  proc_run;   //[pid:start to run]
unordered_map<int,int>  proc_exit;   //[pid:exit time]
priority_queue<Process,vector<Process>,Compare> ready_queue;
int clk;
int idx_procs;
int pid_run=-1;

void admit_procs(void) {
    for(int i=idx_procs;i<procs.size();i++) {
        if(proc_req[i]<=clk) {
            ready_queue.push(procs[i]);
            idx_procs++;
        }
        else    break;
    }
}

void exit_procs(void) {
    if(pid_run==-1) return;
    if(proc_run[pid_run]+procs[pid_run].time_to_use == clk)
    {
        procs[pid_run].state = PROC_ZOMBIE;
        proc_exit[pid_run] = proc_run[pid_run]+procs[pid_run].time_to_use;
        pid_run=-1;
    }
}

// Shorted Process Next
void schedule(void) {
    if(pid_run!=-1 || ready_queue.empty()) return;
    
    Process proc_scheduled = ready_queue.top();
    ready_queue.pop();
    pid_run = proc_scheduled.pid;
    proc_run[pid_run] = clk;
    procs[pid_run].state = PROC_RUN;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int sum_of_turn_around=0;
    sort(jobs.begin(),jobs.end());
    for(int i=0;i<jobs.size();i++) {
        proc_req[i] = jobs[i][0];
        procs.push_back(Process(i,PROC_UNUSED,jobs[i][1]));
    }
    for(;clk<=600000;clk++) {
        exit_procs();
        admit_procs();
        schedule();
    }
    for(int i=0;i<procs.size();i++) {
        int pid = procs[i].pid;
        sum_of_turn_around += (proc_exit[pid]-proc_req[pid]);
    }
    answer = sum_of_turn_around/procs.size();
    return answer;
}
