// O(N^2)

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

struct Log
{
    int begin, end;
    Log(int b,int e):begin(b),end(e){}
};

struct Window
{
    int begin, end;
    Window(int b, int e):begin(b),end(e){}
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

bool isOverlap(Log log, Window window)
{
    if(!(log.begin>window.end || log.end<window.begin)) return true;
    return false;
}

int getThroughputInWindow(vector<Log> logs, Window window)
{
    int throughput=0;
    for(int i=0;i<logs.size();i++)
    {
        if(isOverlap(logs[i],window))   throughput++;
    }
    return throughput;
}

int solution(vector<string> lines) 
{
    int answer = 0;
    vector<Log> logs = Parser(lines);
    for(int i=0;i<logs.size();i++)
    {
        Window left(logs[i].begin-999,logs[i].begin);
        Window right(logs[i].end,logs[i].end+999);

        answer = max(answer, getThroughputInWindow(logs,left));
        answer = max(answer, getThroughputInWindow(logs,right));
    }
    return answer;
}
