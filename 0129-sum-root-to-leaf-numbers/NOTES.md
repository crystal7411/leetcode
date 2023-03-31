각 node 값 : 이전 node 값 * 10 + 현재 node 값

시간 복잡도 : 모든 node를 순회하는 DFS이므로 O(n) 이다.
공간 복잡도 : tree 높이 만큼 stack이 쌓인다. O(h)이며 balanced라는 조건이 없으므로 worst case는 O(n)이다.
