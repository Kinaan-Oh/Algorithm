// 논리: 1) min heap,max heap으로 median 탐색
//      2) window slide 과정에서 front element를 invalidate 필요. 직접 탐색 -> Time Complexity: O(nklgk) 으로 비효율적. 따라서, Lazy Removal Method 적용.
//      3) Lazy Removal을 위해 Invalidated element를 memoize할 HashTable 필요.
//      4) min heap, max heap의 `Valid Element 기준` balancing(n+1:n or n:n+1). Balancing과 관련하여 디테일한 로직 필요.
//      5) 각 min heap, max heap의 top이 Invalid 하면(hashtable 조회) lazy remove(pop).
//      6) For each window sliding, we need O(lgk). So, Total Time Complexity is O(nlgk).
//      익일 구현 예정.
