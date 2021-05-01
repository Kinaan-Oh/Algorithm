// O(record.length)

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct Record {
    string command;
    string uid;
    Record(string c, string u):command(c),uid(u){}
};

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<Record> record_parsed;
    unordered_map<string,string> uid_to_nickname;
    
    for(int i=0;i<record.size();i++) {
        int first = record[i].find_first_of(" ");
        int last = record[i].find_last_of(" ");
        string command = record[i].substr(0,first);
        string uid = record[i].substr(first+1,last-first-1);
        string nickname = record[i].substr(last+1);
        
        if(command=="Enter" || command=="Change")   uid_to_nickname[uid] = nickname;
        record_parsed.push_back(Record(command,uid));
    }
    
    for(int i=0;i<record_parsed.size();i++) {
        if(record_parsed[i].command=="Change") continue;
        
        string message;
        message += (uid_to_nickname[record_parsed[i].uid]+"님이 ");
        if(record_parsed[i].command=="Enter")  message += "들어왔습니다.";
        else    message += "나갔습니다.";
        answer.push_back(message);
    }
    return answer;
}
