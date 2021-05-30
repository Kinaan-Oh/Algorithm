// 출제의도: "Union-Find", Time Complexity: O(nlg*n), Space Complexity: O(n). (n: room_number.size)
// 할당한 방은 다음에 할당할 방의 번호를 가리킨다. 다음에 할당할 방을 할당했을 때, 해당 방을 가리키던 방들의 정보를 해시테이블에서 업데이트 할 수 없음. 따라서, Find(Path Compression)로 재귀적으로 찾아야 함.
// Path Compression으로 구현하여, Find의 n회 반복은 Time Complexity: O(nlg*n)가 됨. 이는 Brute-force하게 구현할 때의 복잡도 O(n^2)보다 훨씬 효율적인 코드.

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long,long long>  room_assigned;

long long find(long long num) {
    if(!room_assigned[num])    return num;
    return room_assigned[num] = find(room_assigned[num]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(int i=0;i<room_number.size();i++) {
        long long req = room_number[i];
        if(!room_assigned[req]) {
            answer.push_back(req);
            room_assigned[req] = find(req+1);
        }
        else {
            long long num_assigned = find(req);
            answer.push_back(num_assigned);
            room_assigned[num_assigned] = find(num_assigned+1);
        }
    }
    return answer;
}
