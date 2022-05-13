// 정확도 통과, 효율성 실패.

#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

void setCategory(unordered_map<int, vector<string>> &category) {
    category[0] = {"cpp", "java", "python"};
    category[1] = {"backend", "frontend"};
    category[2] = {"junior", "senior"};
    category[3] = {"chicken", "pizza"};
}

vector<string> parse(string info) {
    vector<string>  result;
    vector<string>  tmp;
    string s;
    
    for(auto c: info) {
        if(c==' ') {
            tmp.push_back(s);
            s.clear();
        } else {
            s += c;
        }
    }
    tmp.push_back(s);
    
    for(auto elem: tmp) {
        if(elem!="and") {
            result.push_back(elem);
        }
    }
    return result;
}

void materialize(vector<string> target,
                 unordered_map<int, vector<string>> &category,
                 vector<vector<string>> &materialized,
                 int cur,
                 vector<string> query
                 ) {
    if(cur==4) {
        query.push_back(target.back());
        materialized.push_back(query);
        return;
    }
    
    if(target[cur]=="-") {
        for(auto elem: category[cur]) {
            query.push_back(elem);
            materialize(target, category, materialized, cur+1, query);
            query.pop_back();
        }  
    } else {
        query.push_back(target[cur]);
        materialize(target, category, materialized, cur+1, query);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<int, vector<string>> category; // 0:lang, 1:job, 2:exp, 3:soulfood
    vector<vector<string>> parsedInfo;
    vector<vector<string>> parsedQuery;
    unordered_map<string, multiset<int>> db;
    
    setCategory(category);
    
    for(auto elem: info) {
        vector<string> result = parse(elem);
        parsedInfo.push_back(result);
    }
    for(auto elem: parsedInfo) {
        string key = elem[0] + elem[1] + elem[2] + elem[3];
        int score = stoi(elem[4]);
        db[key].insert(score);
    }
    
    for(auto elem: query) {
        vector<string> result = parse(elem);
        parsedQuery.push_back(result);
    }
    for(auto elem: parsedQuery) {
        int result = 0;
        vector<vector<string>> materialized;
        materialize(elem, category, materialized, 0, {});
        
        for(auto query: materialized) {
            string key = query[0] + query[1] + query[2] + query[3];
            int score = stoi(query[4]);
            
            
            if(!db[key].empty()) {
                result += distance(db[key].lower_bound(score), db[key].end());
            } 
        }
        answer.push_back(result);
    }
    return answer;
}
