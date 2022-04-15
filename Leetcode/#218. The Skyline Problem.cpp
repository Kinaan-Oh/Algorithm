// 논리: 1) 각 key point는 이전 buildings의 right top coordinate중 x axis 기준 최대한 큰 우선순위로 current building 의 left top coordinate와 compare 해야 한다.
//      2) 따라서, 각 building의 right top coordinate를 x axis 기본 max heap을 유지한다.
//      3) current building의 left top coordinate와 max heap의 top과 compare. 최초도 height가 current building 보다 크거나 같은 elem 발견할때 까지 pop. 없다면, current
//         building이 key points가 된다.
// 익일 구현 예정.
