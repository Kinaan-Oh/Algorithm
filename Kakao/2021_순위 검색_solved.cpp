// String/Combination(Bitwise)/BinarySearch(LowerBound), Time Complexity: O((MlgL), Space Complexity: O(L) (L: sum of length of info, M: sum of length of queries)
// 기존풀이의 문제점: multiset이 제공하는 lower_bound return type은 bidirectional iterator로 distance는 random access iterator에 대해서만 O(1), 이외
// iterator에 대해서는 O(n). 따라서, lgL로 탐색했지만 distance는 O(L). 따라서, Total Time Complexity O(ML)로 효율성 초과. STL의 multiset을 사용할 수 없는 결정적 이유.
// 따라서, random access iterator를 제공하는 vector 자료구조 선택. Sort and Lower Bound. 마지막 vector는 random access iterator를 제공하므로 distance는 O(1)로 통과 가능.

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

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
    unordered_map<string, vector<int>> query2records;
    
    for(auto elem: info) {
        vector<string> record = parse(elem);
        vector<string> keys = record2keys(record);
        int score = stoi(record[4]);
        
        for(auto key: keys) {
            query2records[key].push_back(score);
        }
    }
    
    for(auto elem: query2records) {
        sort(query2records[elem.first].begin(), query2records[elem.first].end());
    }

    for(auto elem: queries) {
        vector<string> query = parse(elem);
        string key = query[0] + query[1] + query[2] + query[3];
        int score = stoi(query[4]);
        int result = 0;
        
        if(!query2records[key].empty()) {
            result = distance(lower_bound(query2records[key].begin(), query2records[key].end(),score),
                              query2records[key].end());
        }
        answer.push_back(result);
    }
    return answer;
}
