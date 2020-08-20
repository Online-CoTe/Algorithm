#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 100003
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int n, t;

/*
서류 기준으로 정렬한 다음(a,b), 안되는거 지워가고
그 다음에는 면접 기준으로 정렬한 다음(b,a), 안되는거 지워감
*/

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		vector<pi>arr;
		while (n--) {
			int a, b;
			scanf("%d%d", &a, &b);
			arr.push_back({ a,b });
		}

		sort(arr.begin(), arr.end());
		int t = arr[0].second;
		arr[0] = { arr[0].second, arr[0].first };
		for (int i = 1; i < arr.size(); i++)
		{
			if (arr[i].second > t) arr[i] = { INF,INF };
			else {
				t = min(t, arr[i].second);
				arr[i] = { arr[i].second, arr[i].first };
			}
		}

		sort(arr.begin(), arr.end());
		t = arr[0].second;
		for (int i = 1; i < arr.size(); i++)
		{
			if (arr[i].second > t) arr[i] = { INF,INF };
			else t = min(t, arr[i].second);
		}

		sort(arr.begin(), arr.end());
		int ans = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i].first == INF) break;
			ans++;
		}
		printf("%d\n", ans);
	}
}
