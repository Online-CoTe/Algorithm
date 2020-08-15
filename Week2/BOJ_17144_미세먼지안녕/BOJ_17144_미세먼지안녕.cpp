#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000000
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

/*
1. 미세먼지들을 큐에 넣어주고 bfs를 해준다 (백준-토마토 문제와 비슷함)
2. 공기 청정기 바람을 직접 옮겨주기
옮겨주는 코드
int nxt, bfr
nxt = 이번꺼
이번꺼 = bfr
bfr = nxt


(1,1) -------------- (1,c)
   l                          l
 (arr[0], 1)-----(arr[0], c)
 (arr[1], 1)-----(arr[1], c)
   l                          l
(r,1) -------------- (r,c)


*/
int r, c, t;
int arr[55][55];
vector<int>air;
queue<pi>q;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

bool outrange(int x, int y) {
	if (x<1 || y<1 || x> r || y>c) return 1;
	return 0;
}



void dust() {
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (arr[i][j] != 0 && arr[i][j] != -1 && arr[i][j] >= 5)
				q.push({ i,j });
		}
	}
	int tmp[55][55] = { 0, };
	int size = q.size();
	while (size--) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (arr[nx][ny] == -1) continue;
			cnt++;
			tmp[nx][ny] += arr[x][y] / 5;
		}
		arr[x][y] -= (arr[x][y] / 5) * cnt;
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			arr[i][j] += tmp[i][j];
		}
	}

}

void wind() {
	//arr[0]
	// 동쪽
	int bfr = 0, nxt;
	for (int i = 2; i <= c; i++)
	{
		nxt = arr[air[0]][i];
		arr[air[0]][i] = bfr;
		bfr = nxt;
	}

	// ㅣ북쪽
	for (int i = air[0] - 1; i >= 1; i--)
	{
		nxt = arr[i][c];
		arr[i][c] = bfr;
		bfr = nxt;
	}

	//서쪽
	for (int i = c - 1; i >= 1; i--)
	{
		nxt = arr[1][i];
		arr[1][i] = bfr;
		bfr = nxt;
	}

	//남쪽
	for (int i = 2; i < air[0]; i++)
	{
		nxt = arr[i][1];
		arr[i][1] = bfr;
		bfr = nxt;
	}

	//arr[1]
	bfr = 0;
	//동쪽
	for (int i = 2; i <= c; i++)
	{
		nxt = arr[air[1]][i];
		arr[air[1]][i] = bfr;
		bfr = nxt;
	}

	//남쪽
	for (int i = air[1] + 1; i <= r; i++)
	{
		nxt = arr[i][c];
		arr[i][c] = bfr;
		bfr = nxt;
	}

	//서쪽
	for (int i = c - 1; i >= 1; i--)
	{
		nxt = arr[r][i];
		arr[r][i] = bfr;
		bfr = nxt;
	}

	// ㅣ북쪽
	for (int i = r - 1; i > air[1]; i--)
	{
		nxt = arr[i][1];
		arr[i][1] = bfr;
		bfr = nxt;
	}
}

int main() {
	scanf("%d%d%d", &r, &c, &t);

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == -1) air.push_back(i);
		}
	}

	while (t--) {
		dust();
		wind(); 
	}

	int ans = 0;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (arr[i][j] != -1) ans += arr[i][j];
		}
	}

	printf("%d", ans);
}
