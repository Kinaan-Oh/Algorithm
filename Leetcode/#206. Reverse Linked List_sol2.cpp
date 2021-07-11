// "구현-Recursion", Time Complexity: O(n), Space Complexity: O(n) (n: head의 노드 갯수)
// Recursion 구현 방식 또한 생각보다 까다로웠음. 마찬가지로, 마지막 노드의 next를 nullptr로 설정하지 않으면 에러.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next == nullptr)  return head;
        
        ListNode* reversed = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return reversed;
    }
};
