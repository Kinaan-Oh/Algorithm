// Implementation/Combination/Recursion/Heap
// 문제이해에 생각보다 많은 리소스를 소모. 좀 더 명시적으로 문제가 제시되었으면 좋았을 것 같음.
// constraint가 작기 때문에 bottleneck인 combination generation에 worst case 통과가능한 수준인 20*2^10 ~= 10^5 연산필요. 
// 효율성은 무시하고 구현력 측정이 문제출제의도.

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

void setMenuCount(int type, string order, int pos, string menu, unordered_map<string,int> &menu2count) {
    if(menu.length()==type) {
        menu2count[menu] += 1;
        return;
    }
    
    for(int i=pos;i<order.length();i++) {
        setMenuCount(type, order, i+1, menu+order[i], menu2count);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    unordered_map<string,int> menu2count;
    
    for(auto type: course) {
        for(auto order: orders) {
            sort(order.begin(), order.end());
            setMenuCount(type, order, 0, "", menu2count);
        }
    }
    
    for(auto type: course) {
        auto cmp = [](pair<string,int> &a, pair<string,int> &b) {
            return a.second<b.second;
        };
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(cmp)> heap(cmp);
        
        for(auto elem: menu2count) {
            string menu = elem.first;
            int cnt = elem.second;
                
            if(menu.length()==type && cnt>=2)    heap.push({menu, cnt});
        }
        
        if(!heap.empty()) {
            pair<string,int> topElem = heap.top();
            heap.pop();
            answer.push_back(topElem.first);
            
            while(!heap.empty() && heap.top().second==topElem.second) {
                answer.push_back(heap.top().first);
                heap.pop();
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
