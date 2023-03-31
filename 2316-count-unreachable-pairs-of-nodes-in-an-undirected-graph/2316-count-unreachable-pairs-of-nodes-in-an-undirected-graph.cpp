#include <vector>

#define MAXNODE 100001

using namespace std;

int visit[MAXNODE];

class Solution {
public:
	vector<vector<int>> edge;
	vector<bool> visited;
	
	int DFS(int v)
	{
		int num = 1;
		for (int w : edge[v]) // 연결된 모든 노드들에 대해
		{
			if (!visited[w])
			{
				visited[w] = 1;
				num += DFS(w);
			}
		}
		return num;
	}

	long long countPairs(int n, vector<vector<int>>& edges) {

		visited.resize(n);
		fill(visited.begin(), visited.end(), false);
		edge.resize(n);
		for (vector<int>& i : edges)
		{
			edge[i[0]].push_back(i[1]);
			edge[i[1]].push_back(i[0]); //양방향
		}

		// dfs를 이용해서 각각에 연결된 수를 구한다.
		vector<int> counts;

		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				visited[i] = 1;
				counts.push_back(DFS(i));
			}
		}

		/* 시간 초과... */
		/*
		long long result = 0; // 결과를 저장할 변수
		for (int i = 0; i < counts.size(); i++) { // 모든 요소에 대해 탐색
			for (int j = i + 1; j < counts.size(); j++) { // i 다음 요소부터 탐색
				result += (long long)counts[i] * counts[j]; // 2개씩 곱하고 더하기
			}
		}
		*/

		long long sum = 0, answer = 0;
		for (int count : counts) {
			sum += (long long)count;
		}

		for (int i = 0; i < counts.size(); i++) {
			sum -= (long long)counts[i];
			answer += (long long)counts[i] * sum;
		}
		return answer;
	}
};