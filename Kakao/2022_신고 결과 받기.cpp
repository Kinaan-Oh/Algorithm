// HashTable/HashSet, Time Complexity: O(l+mn), Space Complexity: O(l) (m: id_list.size, n: reports.size, l: sum of reports length)

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> reports, int k) {
    vector<int> answer;
    unordered_map<string, unordered_set<string>>  id2reports;
    unordered_map<string, int>  id2numReported;
    
    for(auto report: reports) {
        auto pos = report.find_first_of(" ");
        string reporter = report.substr(0, pos);
        string target = report.substr(pos+1);
        id2reports[reporter].insert(target);
    }
    
    for(auto elem: id2reports) {
        for(auto id: elem.second) {
            id2numReported[id] += 1;
        }
    }
    
    for(auto id: id_list) {
        int cnt = 0;
        
        for(auto target: id2reports[id]) {
            if(id2numReported[target]>=k) {
                cnt += 1;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}
