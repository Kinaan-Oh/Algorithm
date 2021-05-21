// 출제의도: "우선순위 큐", Time Complexity: O(nlgn), Space Complexity: O(n). (n: operations.size)

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

priority_queue<int,vector<int>,greater<int>>    min_heap;
priority_queue<int> max_heap;
unordered_map<int,int>  num_of_elem;    // [elem:num]
int num_of_elems;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for(int i=0;i<operations.size();i++) {
        int num = stoi(operations[i].substr(2));

        switch(operations[i][0]) {
            case 'I':
                max_heap.push(num);
                min_heap.push(num);
                num_of_elem[num]++;
                num_of_elems++;
                break;

            case 'D':
                if(!num_of_elems)    continue;

                if(num==1) {
                    while(num_of_elem[max_heap.top()]==0) {
                        max_heap.pop();
                    }
                    num_of_elem[max_heap.top()]--;
                    max_heap.pop();
                }
                else {
                    while(num_of_elem[min_heap.top()]==0) {
                        min_heap.pop();
                    }
                    num_of_elem[min_heap.top()]--;
                    min_heap.pop();
                }
                num_of_elems--;
                break;
        }
    }
    if(num_of_elems==0) answer = {0,0};
    else {
        while(num_of_elem[max_heap.top()]==0) {
            max_heap.pop();
        }
        answer.push_back(max_heap.top());
        while(num_of_elem[min_heap.top()]==0) {
            min_heap.pop();
        }
        answer.push_back(min_heap.top());
    }
    return answer;
}
