// 출제의도: LinkedList/ Two-Pointer, Time Complexity: O(L), Space Complexity: O(1) (L: 리스트 노드 갯수)
// L의 크기를 먼저 구하는 2-pass 풀이를 먼저 생각했지만, Two-Pointer를 이용해 1-pass로 개선한 풀이.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* front = head;
        ListNode* end = head;
        for(int i=0;i<n;i++)    end = end->next;
        if(end==nullptr)    return head->next;
        while(end->next) {
            front = front->next;
            end = end->next;
        }
        front->next = front->next->next;
        return head;
    }
};
