// "슬라이딩 윈도우, 멀티셋", Time Complexity: O(nlgn), Space Complexity: O(n). (n: stones.size)
// 길이가 k인 윈도우가 연속된 0이 되게 하기 위해서 해당 윈도우내 최대값의 인원이 이동하면 됨. 윈도우를 슬라이딩해주면서 연속된 0으로 만들 수 있는 최대값들 중의 최소값이 답이 됨.
// 이를 위해, 윈도우 내 원소들을 1) 중복을 허용하고 2) 내부적으로 정렬되어 최댓값을 쉽게 찾을 수 있는 3) 임의의 원소의 위치를 찾고 제거하는 기능을 가진 자료구조가 필요.
// 이를 만족하는 자료구조는 multiset 혹은 multimap 뿐인데, multiset 만으로 충분하여 해당 자료구조를 선택.(우선순위 큐의 경우 3번 조건을 만족하지 못하여 사용할 수 없음.)
// multiset은 balanced BST이므로 find, erase, insert의 시간복잡도는 O(lgn).
// 따라서 전체 시간복잡도는 k==1일때 O(n)이지만, k==n일때 O(nlgn)이므로(n개의 원소를 multiset에 삽입) O(nlgn)이 됨.

#include <string>
#include <vector>
#include <set>
#include <climits>
#include <iostream>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = INT_MAX;
    multiset<int>  window;
    int left=0, right=k-1;
    for(int i=0;i<k;i++)    window.insert(stones[i]);
    
    while(right<stones.size()) {
        answer = min(answer, *--window.end());
        window.erase(window.find(stones[left]));
        window.insert(stones[right+1]);
        left++, right++;
    }
    return answer;
}
