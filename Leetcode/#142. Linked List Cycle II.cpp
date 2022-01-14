// 출제의도: Two-pointer(walker/runner)/Math, Time Complexity: O(n), Space Complexity: O(1). (n: list의 모든 노드 갯수)
// idea: 약간의 계산을 통해 walker와 runner가 만나는 지점은 cycle 길이의 정수배 라는 사실을 도출해낼 수 있다. 
// 따라서, 만난 지점으로부터 시작점~사이클시작점 거리 만큼 이동한다면 사이클지점에 도달함이 보장된다.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr)    return nullptr;
        
        ListNode* walker = head;
        ListNode* runner = head;
        
        do {
            walker = walker->next;
            runner = runner->next->next;
            
            if(runner==nullptr || runner->next==nullptr)    return nullptr;
        } while(walker != runner);
        
        walker = head;
        
        while(walker != runner) {
            walker = walker->next;
            runner = runner->next;
        }
        return walker;
    }
};
