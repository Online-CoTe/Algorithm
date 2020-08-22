#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x;
	int y;
	char c;
};


bool visit[75][75];
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
char map[75][75];
int cnt, puyo;
queue<node>q;

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= 12 || y >= 6) return 1;
	else return 0;
}

void dfs(int x, int y) {
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (outrange(nx, ny)) continue;
		if (map[nx][ny] != map[x][y]) continue;
		if (visit[nx][ny]) continue;

		visit[nx][ny] = 1;
		cnt++;
		if (cnt == 4) q.push({ nx,ny,map[nx][ny] });
		dfs(nx, ny);
	}
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		char c = q.front().c;
		visit[x][y] = 1;
		map[x][y] = '.';
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (map[nx][ny] != c) continue;
			if (visit[nx][ny]) continue;

			visit[nx][ny] = 1;
			map[nx][ny] = '.';
			q.push({ nx,ny,c });
		}
	}
}

void init() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			visit[i][j] = 0;
}


int main() {

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			scanf(" %c", &map[i][j]);

	while (1) {
		//search
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (visit[i][j]) continue;
				if (map[i][j] == '.') continue;
				cnt = 1;
				dfs(i, j);
			}
		}
		init();

		if (q.empty()) { printf("%d", puyo); return 0; }

		//pop
		bfs();
		init();
		puyo++;

		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 11; k++)
			{
				for (int i = 10; i >= k; i--)
				{
					if (map[i + 1][j] == '.') {
						map[i + 1][j] = map[i][j];
						map[i][j] = '.';
					}
				}
			}
		}
	}
}
