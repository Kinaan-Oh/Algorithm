// 출제의도: "우선순위 큐, SPN", Time Complexity: O(nlgn), Space Complexity: O(n). (n: jobs.size)

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

struct Process {
    int pid;
    int req_time;
    int run_time;
    int exit_time;
    Process(int p,int req,int run):pid(p),req_time(req),run_time(run),exit_time(-1){}
};

struct Compare {
    bool operator()(Process &p1, Process &p2) {
        return p1.run_time>p2.run_time;
    }
};

vector<Process> procs;
priority_queue<Process,vector<Process>,Compare> ready_queue;
int idx_of_procs;
int clk;

void admit_procs(void) {
    for(int i=idx_of_procs;i<procs.size();i++) {
        if(procs[i].req_time<=clk) {
            ready_queue.push(procs[i]);
            idx_of_procs++;
        }
        else    return;
    }
}

// Shortest Process Next
void schedule(void) {
    if(ready_queue.empty()) {
        clk = procs[idx_of_procs].req_time;
        return;
    }
    
    Process proc_scheduled = ready_queue.top();
    ready_queue.pop();
    clk += proc_scheduled.run_time;
    procs[proc_scheduled.pid].exit_time = clk;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int total_turn_around=0;
    sort(jobs.begin(),jobs.end());
    for(int i=0;i<jobs.size();i++) {
        procs.push_back(Process(i,jobs[i][0],jobs[i][1]));
    }
    while(!(idx_of_procs==procs.size() && ready_queue.empty())) {
        admit_procs();
        schedule();
    }
    for(int i=0;i<procs.size();i++) {
        total_turn_around += (procs[i].exit_time - procs[i].req_time);
    }
    answer = total_turn_around/procs.size();
    return answer;
}
