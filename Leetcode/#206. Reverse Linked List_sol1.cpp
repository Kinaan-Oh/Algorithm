// "구현", Time Complexity: O(n), Space Complexity: O(1). (n: head의 노드 갯수)
// 각 노드의 next를 직전 노드를 가리키도록 함. 실제 구현은 생각보다 까다로웠음.
// 주의: 첫번째 노드의 next를 nullptr로 설정하지 않으면 cycle이 발생하여 heap-use-after-free 에러 발생. 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)    return head;
        
        ListNode* prev = head, *cur = head->next;
        prev->next = nullptr;
        
        while(cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
