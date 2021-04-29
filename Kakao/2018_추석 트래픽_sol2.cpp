// Sliding Window. O(NlgN): 정렬 부분이 병목. 2021 라인 상반기 3번문제와 동일 유형.

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

struct Log
{
    int begin, end;
    Log(int b,int e):begin(b),end(e){}
};

int StoMsec(string S)
{
    int h = stoi(S.substr(0,2))*60*60*1000;
    int m = stoi(S.substr(3,2))*60*1000;
    int s = stoi(S.substr(6,2))*1000;
    int ms = stoi(S.substr(9,3));
    return (h+m+s+ms);
}

int TtoMsec(string T)
{
    T.pop_back();
    int s = stoi(T.substr(0,1))*1000;
    if(T.size()==1) return s;
    int ms = stoi(T.substr(2));
    return (s+ms);
}

vector<Log> Parser(vector<string> lines)
{
    vector<Log> logs;
    for(int i=0;i<lines.size();i++)
    {
            char *cstr = new char[lines[i].length()+1];
            strcpy(cstr, lines[i].c_str());
            char *p = strtok(cstr," ");
            int begin, end, interval;
            int cnt = 0;
            while(p!=NULL)
            {
                if(cnt==1)  end = StoMsec(string(p));
                else if(cnt==2)
                {
                    interval = TtoMsec(string(p));
                    begin = end-interval+1;
                }
                p = strtok(NULL," ");
                cnt++;
            }
            logs.push_back(Log(begin,end));
            delete[] cstr;
    }
    return logs;
}

int solution(vector<string> lines) 
{
    int maxThroughputPerSecond = 0;
    int throughputInLastSecond=0;
    vector<Log> logs = Parser(lines);
    
    vector<int> requests;
    vector<int> responses;
    int idx_req=0, idx_res=0;
    for(int i=0;i<logs.size();i++)
    {
        requests.push_back(logs[i].begin);
        responses.push_back(logs[i].end);
    }
    sort(requests.begin(),requests.end());
    sort(responses.begin(),responses.end());
    
    while(idx_req<requests.size())
    {
        bool Include = requests[idx_req]<responses[idx_res]+1000 ? true : false;
        if(Include)
        {
            throughputInLastSecond++;
            idx_req++;
        }
        else
        {
            throughputInLastSecond--;
            idx_res++;
        }
        maxThroughputPerSecond = max(maxThroughputPerSecond, throughputInLastSecond);
    }
    return maxThroughputPerSecond;
}
