#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

//int visit[201][201];

int dx[4] = { 0, 1 };
int dy[4] = { 1, 0 };

// sum을 가장 작게 하는 path찾기
class Solution {
	int m; 
	int n;

	int dist[201][201];
public:
	void bfs(vector<vector<int>>& grid)
	{
		queue<pair<int, int>> q;
		dist[0][0] = grid[0][0];
		q.push({ 0, 0 });

		while (!q.empty())
		{
			int curx = q.front().first; 
			int cury = q.front().second;

			printf("curx : %d cury : %d\n", curx, cury);
			q.pop();

			for (int i = 0; i < 2; i++)
			{
				int nx = curx + dx[i];
				int ny = cury + dy[i];

				if (nx < 0 || nx >= m || ny < 0 || ny >= n)
					continue;

				if (dist[nx][ny] > dist[curx][cury] + grid[nx][ny])
				{
					printf("x : %d y : %d\n", nx, ny);
					dist[nx][ny] = dist[curx][cury] + grid[nx][ny];
					q.push({ nx, ny });
				}
			}
		}
	}

	int minPathSum(vector<vector<int>>& grid) {
		
		m = grid.size();
		n = grid[0].size();

		for (int i = 0; i < 201; i++)
		{
			for (int j = 0; j < 201; j++)
			{
				dist[i][j] = INT_MAX;
			}
		}

		bfs(grid);

		printf("%d, %d - %d\n", m - 1, n - 1, dist[m - 1][n - 1]);

		return dist[m - 1][n - 1];
	}
};
