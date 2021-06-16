// Time Complexity: O(nlgn), Space Complexity: O(n).
// Merge Sort(Bottom-up)를 이용하면 Space Complexity를 O(1)로 단축시킬 수 있다. 1시간이란 제한시간동안 구현하는 것에는 실패하였고, 좋은 솔루션(하단 주석)을 참고하여 코드를 분석해보았다.
// 1. bottom-up 방식으로 길이가 1,2,4,8,.. 순으로 2의 지수승 크기(n보다 작은) 부분 리스트들을 merge한다.
// 2. 두 부분 리스트로 split하는 과정이 필요한데, 예를들어 merge할 연속된 길이 2인 두 부분리스트의 head를 구한다. 이는 walker/runner 기법을 이용하여 mid를 찾고 mid를 뒤쪽 부분리스트의 head로 한다.
// 3. merge는 일반적인 merge sort와 같다. 두 리스트 원소를 앞에서 부터 비교하면서 작은 것을 새로운 리스트에 추가한다. 한 리스트의 끝에 도달하면, 다른 리스트의 남은 부분을 새로운 리스트의 뒤에 붙여준다.

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr)   return nullptr;
        
        vector<int> list;
        for(ListNode* i=head;i!=nullptr;i=i->next) {
            list.push_back(i->val);
        }
        sort(list.begin(),list.end());
        ListNode* sortList = new ListNode(list[0]);
        ListNode* cur = sortList;
        for(int i=1;i<list.size();i++) {
            cur->next = new ListNode(list[i]);
            cur = cur->next;
        }
        return sortList;
    }
};


// class Solution {
// public:
//     ListNode* tail = new ListNode();
//     ListNode* nextSubList = new ListNode();

//     ListNode* sortList(ListNode* head) {
//         if (!head || !head -> next)
//             return head;
//         int n = getCount(head);
//         ListNode* start = head;
//         ListNode dummyHead(0);
//         for (int size = 1; size < n; size = size * 2) {
//             tail = &dummyHead;
//             while (start) {
//                 if (!start->next) {
//                     tail->next = start;
//                     break;
//                 }
//                 ListNode* mid = split(start, size);
//                 merge(start, mid);
//                 start = nextSubList;
//             }
//             start = dummyHead.next;
//         }
//         return dummyHead.next;
//     }

//     ListNode* split(ListNode* start, int size) {
//         ListNode* midPrev = start;
//         ListNode* end = start->next;
//         //use fast and slow approach to find middle and end of second linked list
//         for (int index = 1; index < size && (midPrev->next || end->next); index++) {
//             if (end->next) {
//                 end = (end->next->next) ? end->next->next : end->next;
//             }
//             if (midPrev->next) {
//                 midPrev = midPrev->next;
//             }
//         }
//         ListNode* mid = midPrev->next;
//         nextSubList = end->next;
//         midPrev->next = nullptr;
//         end->next = nullptr;
//         // return the start of second linked list
//         return mid;
//     }

//     void merge(ListNode* list1, ListNode* list2) {
//         ListNode dummyHead(0);
//         ListNode* newTail = &dummyHead;
//         while (list1 && list2) {
//             if (list1->val < list2->val) {
//                 newTail->next = list1;
//                 list1 = list1->next;
//                 newTail = newTail->next;
//             } else {
//                 newTail->next = list2;
//                 list2 = list2->next;
//                 newTail = newTail->next;
//             }
//         }
//         newTail->next = (list1) ? list1 : list2;
//         // traverse till the end of merged list to get the newTail
//         while (newTail->next) {
//             newTail = newTail->next;
//         }
//         // link the old tail with the head of merged list
//         tail->next = dummyHead.next;
//         // update the old tail with the new tail of merged list
//         tail = newTail;
//     }

//     int getCount(ListNode* head) {
//         int cnt = 0;
//         ListNode* ptr = head;
//         while (ptr) {
//             ptr = ptr->next;
//             cnt++;
//         }
//         return cnt;
//     }
// };

