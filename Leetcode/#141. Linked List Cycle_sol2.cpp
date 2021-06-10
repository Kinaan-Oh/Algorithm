// "Folyd's Cycle Finding Algorithm", Time Complexity: O(n), Space Complexity: O(1). (n: list 노드 갯수)
// 접해보지 못한 흥미로운 알고리즘. 연병장에서 3km 달리기를 해본 경험이 있다면 직관적으로 쉽게 이해가 가능.
// runner는 walker보다 2배 빠른 속도로 리스트를 이동한다고 가정하자. 
// 1. cycle이 없다면, runner는 리스트의 끝(nullptr)에 도달. n/2번 반복하므로 이 경우 Time Complexity는 O(n). (sol1보다 실제로는 절반의 비교 연산만 필요하다.)
// 2. cycle이 있다면, runner는 walker보다 먼저 cycle에 진입하고, walker가 cycle에 진입했을때 runner는 cycle내 임의의 위치에 존재하게 된다.(위치는 cycle의 길이에 따라 달라진다.)
// cycle에 진입한 walker를 runner는 언젠간 따라잡게 되는데 최악의 경우 cycle의 길이만큼 반복된다. 
// 1) walker가 cycle진입점까지 이동하는데 필요한 반복 + 2) cycle에 진입한 walker를 runner가 따라잡는데 걸리는 최악의 반복 = n. 따라서, cycle이 있는 경우, 마찬가지로 Time Complexity는 O(n).
// 1. 2. 두 경우를 종합하여 Floy'd Cycle Finding Algorithm의 Time Complexity는 O(n)이고 Space Complexity가 O(1)이라는 점에서 sol1보다 우월하다.

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *walker=head, *runner=head;
        while(runner!=nullptr) {
            walker = walker->next;
            runner = runner->next ? runner->next->next : nullptr;
            if(runner && walker==runner)  return true;
        }
        return false;    
    }
};
