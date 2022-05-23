// List/Stack, Time Complexity: O(L), Space Complexity: O(n) (L: sum of X)
// L<=10^6 조건에 의해 통과가능. 
// 삽입/삭제 연산 O(1) 제공하는 List 자료구조 채택. LIFO 구조로 Z명령어 처리에 적합한 Stack 자료구조 채택.
// STL List 풀이시 알 수 없는 오류로 인해 직접 List 구현.

#include <string>
#include <vector>
#include <stack>

struct ListNode {
    int val;
    ListNode *prev, *next;
    ListNode(int val, ListNode* prev, ListNode* next) : val(val), prev(prev), next(next) {}
};

ListNode* advance(ListNode *p, int n) {
    if(n>0) {
        for(int i=0;i<n;i++)  p = p->next;
    } else {
        for(int i=0;i<abs(n);i++)  p = p->prev;
    }
    return p;
}

using namespace std;

string solution(int n, int k, vector<string> cmdList) {
    string answer(n, 'X');
    ListNode *head = new ListNode(0, nullptr, nullptr);
    ListNode *p = head;
    stack<ListNode*> stack;
    
    for(int i=1;i<n;i++) {
        p->next = new ListNode(i, p, nullptr);
        p = p->next;
    }
    
    p = advance(head,k);
    
    for(auto cmd: cmdList) {
        if(cmd[0]=='U') {
            int x = stoi(cmd.substr(2));
            p = advance(p,-x);
        } else if(cmd[0]=='D') {
            int x = stoi(cmd.substr(2));
            p = advance(p,x);
        } else if(cmd[0]=='C') {
            stack.push(p);
            if(p==head)  head = head->next;
            
            if(p->prev!=nullptr)  p->prev->next = p->next;
            if(p->next!=nullptr)  p->next->prev = p->prev;
            
            if(p->next==nullptr)  p = p->prev;
            else  p = p->next;
        } else if(cmd[0]=='Z') {
            ListNode *s = stack.top(); stack.pop();
            if(s->prev!=nullptr)  s->prev->next = s;
            if(s->next!=nullptr)  s->next->prev = s;
            
            if(s->next==head)  head = s;
        }
    }
    
    for(auto it=head;it!=nullptr;it=it->next) {
        answer[it->val] = 'O';
    }
    return answer;
}
