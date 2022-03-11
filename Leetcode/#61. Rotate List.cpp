// Linked List/Two Pointer, Time Complexity: O(n), Space Complexity: O(1) (n: num of nodes)
// 논리: 전체 노드 갯수 만큼의 rotate는 원점이므로 k>num of nodes일 경우, k%num of nodes회 rotate한 것과 같다.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr)   return nullptr;
        
        ListNode* a = head;
        ListNode* b = head;
        ListNode* tmp = head;
        int size = 0;
        
        while(tmp) {
            tmp = tmp->next;
            size += 1;
        }
        
        for(int i=0;i<k%size;i++) {
            b = b->next;
        }
        while(b->next) {
            a = a->next;
            b = b->next;
        }
        b->next = head;
        head = a->next;
        a->next = nullptr;
        return head;
    }
};
