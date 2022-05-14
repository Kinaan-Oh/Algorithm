// 정확도 통과, 효율성 실패.
// multiset보다 효율적인 자료구조 고민 필요.

#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> parse(string info) {
    vector<string>  result;
    stringstream ss;
    string tmp;
    
    ss.str(info);
    while(ss>>tmp) {
        if(tmp!="and") {
            result.push_back(tmp);
        }
    }
    return result;
}

vector<string> record2keys(vector<string> record) {
    vector<string> result;
    int b=0;
    
    while(b<16) {
        string key;
        int c=1;
        
        for(int i=3;i>=0;i--,c<<=1) {
            if(b&c) {
                key = record[i] + key;
            } else {
                key = "-" + key;
            }
        }
        result.push_back(key);
        b += 1;
    }
    return result;
}

vector<int> solution(vector<string> info, vector<string> queries) {
    vector<int> answer;
    unordered_map<string, multiset<int>> query2records;
   
    for(auto elem: info) {
        vector<string> record = parse(elem);
        vector<string> keys = record2keys(record);
        int score = stoi(record[4]);
        
        for(auto key: keys) {
            query2records[key].insert(score);
        }
    }  

    for(auto elem: queries) {
        vector<string> query = parse(elem);
        string key = query[0] + query[1] + query[2] + query[3];
        int score = stoi(query[4]);
        int result = 0;
        
        if(!query2records[key].empty()) {
            result = distance(query2records[key].lower_bound(score), query2records[key].end());
        }
        answer.push_back(result);
    }
    return answer;
}
