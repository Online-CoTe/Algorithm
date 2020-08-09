#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, m, k;
int arr[105][105];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
queue<pi>q;
vector<pi>c;

bool outrange(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>n-1) return 1;
	return 0;
}

int ans=INF;
int check[15];

int bfs() {

	int dist[55][55];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = INF;

	for (int i = 0; i < c.size(); i++)
	{
		if (check[i]) {
			q.push({ c[i].first,c[i].second });
			dist[c[i].first][c[i].second] = 0;
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int d = dist[x][y];
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny))continue;
			if (dist[nx][ny] > dist[x][y] + 1) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] == 1) { sum += dist[i][j]; }

	return sum;
}

void C(int idx, int k) {
	if (k == m) {
		int tmp = bfs();
		ans = min(tmp, ans);
	}

	for (int i = idx; i < c.size(); i++)
	{
		if (check[i]) continue;
		check[i] = 1;
		C(i, k + 1);
		check[i] = 0;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) c.push_back({i,j});
		}

	C(0, 0);
	printf("%d", ans);
}
