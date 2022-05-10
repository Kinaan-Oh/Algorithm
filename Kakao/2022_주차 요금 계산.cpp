// String/BST, Time Complexity: O(nlgn+l), Space Complexity: O(l) (n: num of records, l: sum of length of records)
// 차량번호가 작은 순으로 계산하기 위해 내부적으로 BST로 구현된 map 자료구조 선택. (hashmap을 선택하고 sort해줄수도 있음)

#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int timeToMinute(string time) {
    int h = stoi(time.substr(0,2));
    int m = stoi(time.substr(3,2));
    return 60*h+m;
}

int getFee(vector<int> fees, int time) {
    if(time<=fees[0])   return fees[1];
    
    int extraCharge = ceil((time-fees[0])/(double)fees[2]) * fees[3]; 
    return fees[1] + extraCharge;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string,vector<string>> carNo2records;
    
    for(auto record: records) {
        string time = record.substr(0,5);
        string carNo = record.substr(6,4);
        carNo2records[carNo].push_back(time);
    }
    
    for(auto elem: carNo2records) {
        int time = 0;
        
        for(int i=0;i<elem.second.size()-1;i+=2) {
            time += (timeToMinute(elem.second[i+1]) - timeToMinute(elem.second[i]));
        }
        if(elem.second.size()%2==1) {
            time += (timeToMinute("23:59") - timeToMinute(elem.second.back()));
        }
        answer.push_back(getFee(fees,time));
    }
    return answer;
}
